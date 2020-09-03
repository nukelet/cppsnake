/*
    convention: (x,y)
*/
#ifndef SNAKE
#define SNAKE

#include <vector>
#include <utility>

typedef std::pair<int, int> position;
typedef std::pair<int, int> direction;
typedef std::vector<position> body;

class Snake
{
    public:

    Snake();
    Snake(const position& StartingPosition, 
          const direction& StartingDirection);
    position get_head() const;
    position get_tail() const;
    body get_body() const;
    void set_direction(const direction& NewDirection);  // TODO: test for reference issues
    void update_snake(); // TODO: consider maybe returning some kind of game over flag?
    // void grow_snake();  // attaches one block to the head?
    
    private:

    body mSnakeBody;    // head: mSnakeBody.begin()
    direction mSnakeHeadDirection;
};

#endif