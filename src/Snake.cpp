#include "Snake.h"

Snake::Snake()
{
    position StartingPosition = std::make_pair<int, int>(0, 0);
    position StartingDirection = std::make_pair<int, int>(1, 0);    // points to the right

    mSnakeBody.push_back(StartingPosition);
    mSnakeHeadDirection = StartingDirection;
}

Snake::Snake(const position& StartingPosition, const direction& StartingDirection)
{
    mSnakeBody.push_back(StartingPosition);
    mSnakeHeadDirection = StartingDirection;
}

position Snake::get_head() const
{
    return mSnakeBody.front();
}

position Snake::get_next_head() const
{
    position Head = mSnakeBody.front();

    // vector sum
    position NextHeadPosition = std::make_pair<int, int> (
        Head.first + mSnakeHeadDirection.first, 
        Head.second + mSnakeHeadDirection.second);

    return NextHeadPosition;
}

position Snake::get_tail() const
{
    return mSnakeBody.back();
}

body Snake::get_body() const
{
    return mSnakeBody;
}

int Snake::get_size() const
{
    return mSnakeBody.size();
}

bool Snake::is_in_body(const position& Point) const
{
    if (std::find(mSnakeBody.begin(), mSnakeBody.end(), Point) != mSnakeBody.end())
        return true;
    else
        return false;
}

void Snake::set_direction(const direction& NewDirection)
{
    mSnakeHeadDirection = NewDirection;
}

// move head in the direction of mSnakeDirection, delete tail
void Snake::move_snake()
{
    position NextHeadPosition = get_next_head();


    mSnakeBody.insert(mSnakeBody.begin(), NextHeadPosition);     // move head forward
    mSnakeBody.erase(mSnakeBody.end() - 1);                     // delete tail
}

void Snake::grow_snake(const position& NewHead) 
{
    mSnakeBody.insert(mSnakeBody.begin(), NewHead); // insert "new head"
}

void Snake::teleport_head(const position& NewPosition)
{
    mSnakeBody.insert(mSnakeBody.begin(), NewPosition);     // add new head position
    mSnakeBody.erase(mSnakeBody.end() - 1);                 // delete tail
}

// #include <cstdio>

// int main()
// {
//     Snake my_snake;
//     printf("Snake head on position (%d, %d)\n", 
//             my_snake.get_head().first, 
//             my_snake.get_head().second);

//             return 0;
// }
