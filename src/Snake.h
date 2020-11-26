/*
    convention: (y, x), with (0,0) being the upper left corner of the window
*/
#ifndef SNAKE
#define SNAKE

#include "types.h"

#include <vector>       // std::vector
#include <utility>      // std::pair
#include <algorithm>    // std::find()

class Snake
{
    private:

    body mSnakeBody;    // head: mSnakeBody.begin()
    
    public:

    Snake() = delete; // prevents initialization with the default constructor
    Snake(position StartingPosition);

    position get_head() const;
    body& get_body();
    size_t get_size() const;

    bool is_in_body(const position& Point) const;    // returns true if it is, false otherwise
    
    // pushes a new head and pops tail
    void update_position(position NewHeadPosition);
    
    // for growing the snake when eating
    void insert_new_head(position NewHeadPosition);
};

#endif