/*
    convention: (x,y), (0,0) being the upper left corner of the window
*/
#ifndef SNAKE
#define SNAKE

#include "types.h"

#include <vector>       // std::vector
#include <utility>      // std::pair
#include <algorithm>    // std::find()

class Snake
{
    public:

    Snake();
    Snake(const position& StartingPosition, 
          const direction& StartingDirection);

    position get_head() const;
    position get_next_head() const;
    position get_tail() const;  // TODO: is this really needed?
    body get_body() const;  // TODO: consider returning by reference for memory efficiency
    int get_size() const;
    bool is_in_body(const position& Point) const;    // returns true if it is, false otherwise

    void set_direction(const direction& NewDirection);  // TODO: test for reference issues
    
    
    /*  TODO: consider maybe returning some kind of game over flag?
        ***should be the last thing to be called in each frame***
    */
    void move_snake(); 


    /*  adds one block to the front of the queue (effectively
        effectively creating a new head)
        TODO: throw exception when the new head is not
        attached to the previous head
    */
    
    void grow_snake(const position& NewHead);

    // bool check_collision(const position& Point) const;
    void teleport_head(const position& NewPosition);
    
    private:

    body mSnakeBody;    // head: mSnakeBody.begin()
    direction mSnakeHeadDirection;
};

#endif