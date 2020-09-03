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

position Snake::get_tail() const
{
    return mSnakeBody.back();
}

body Snake::get_body() const
{
    return mSnakeBody;
}

void Snake::set_direction(const direction& NewDirection)
{
    mSnakeHeadDirection = NewDirection;
}

// move head in the direction of mSnakeDirection, delete tail
void Snake::update_snake()
{
    position Head = mSnakeBody.front();

    // vector sum
    position NewHeadPosition = std::make_pair<int, int> (Head.first + mSnakeHeadDirection.first, Head.second + mSnakeHeadDirection.second);

    mSnakeBody.insert(mSnakeBody.begin(), NewHeadPosition);     // move head forward
    mSnakeBody.erase(mSnakeBody.end() - 1);                     // delete tail
}

#include <cstdio>

int main()
{
    Snake my_snake;
    printf("Snake head on position (%d, %d)\n", 
            my_snake.get_head().first, 
            my_snake.get_head().second);

            return 0;
}
