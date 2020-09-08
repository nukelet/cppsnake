#include "Graphics.h"

Graphics::Graphics()
{
    
}

void Graphics::refresh_buffer()
{
    for (int y = 0; y < mHeight + 2; y++)
    {
        for (int x = 0; x < mWidth + 2; x++)
        {
            if (x == 0 || y == 0 || x == mWidth + 1 || y == mHeight + 1)
                mScreen[y][x] = '#';

            else
                mScreen[y][x] = ' ';
        }
    }
}

void Graphics::draw_screen(const Environment& CurrentEnvironment)
{
    refresh_buffer();
    body SnakeBody = CurrentEnvironment.get_snake_body();
    food_location FoodLocation = CurrentEnvironment.get_food_location();

    // draw snake; using mScreen[y+1][x+1] due to screen borders
    // in the 0th line

    for (auto it = SnakeBody.begin(); it != SnakeBody.end(); ++it)
    {
        mScreen[it->second+1][it->first+1] = 'O';
    }

    for (auto it = FoodLocation.begin(); it != FoodLocation.end(); ++it)
    {
        mScreen[it->second+1][it->first+1] = '*';
    }

    for (int y = 0; y < mHeight + 2; y++)
    {
        for (int x = 0; x < mWidth + 2; x++)
        {
            printf("%c", mScreen[y][x]);
        }
        
        printf("\n");
    }
}

// int main()
// {
//     Environment MyEnvironment;
//     Graphics MyScreen;

//     MyScreen.draw_screen(MyEnvironment);

//     return 0;
// }