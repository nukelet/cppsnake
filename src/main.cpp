#include <ncurses.h>
#include "Environment.h"

int main(int argc, char const *argv[])
{
    // ncurses configs

    // start curses mode
    initscr();

    // doesn't receive SIGINT/SIGSTP signals from
    // keyboard shortcuts (CTRL-C/CTRL-Z)
    raw();

    // makes getch() wait for user input for 0.1 seconds
    // before returning ERR
    halfdelay(1);

    // doesn't print character caught in getch()
    noecho();

    // makes cursor invisible
    curs_set(0);

    const int width = 60, height = 30;

    // create window
    WINDOW* GameOverlay = newwin(2, width, 0, 0);
    WINDOW* GameScreen = newwin(height, width, 2, 0);


    // create Environment
    Environment env = Environment(height, width);

    // begin game loop
    while(true)
    {
        wclear(GameScreen);
        wclear(GameOverlay);

        // draw game screen
        for (auto it : env.get_snake_body())
            mvwaddch(GameScreen, it.first, it.second, 'o');

        for (auto it : env.get_food_location())
            mvwaddch(GameScreen, it.first, it.second, '*');

        wrefresh(GameScreen);

        // draw game overlay
        wprintw(GameOverlay, "SCORE: %d\nPress 'q' to exit", env.get_score());
        wrefresh(GameOverlay);

        char c = getch();

        if (c == 'q')
            break;

        /*
            arrows: 
                '\033[A' = ARROW_UP
                '\033[B' = ARROW_DOWN
                '\033[C' = ARROW_RIGHT
                '\033[D' = ARROW_LEFT
        */

        if (c == '\033')
        {
            getch(); // to skip the '['
            
            switch(getch())
            {
                case 'A':
                    env.set_mov_direction(std::make_pair(-1, 0));
                    break;

                case 'B':
                    env.set_mov_direction(std::make_pair(1, 0));
                    break;

                case 'C':
                    env.set_mov_direction(std::make_pair(0, 1));
                    break;

                case 'D':
                    env.set_mov_direction(std::make_pair(0, -1));
                    break;
            }
        }

        if (env.update_environment() == GAME_OVER)
        {
            wclear(GameOverlay);
            wprintw(GameOverlay, "SCORE: %d\nGAME OVER! Press any key to exit", env.get_score());
            wrefresh(GameOverlay);
            cbreak(); getch();
            break;
        }
    }

    // end curses mode
    endwin();

    return 0;
}