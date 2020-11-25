#include "Snake.h"

#include <algorithm>

Snake::Snake(position StartingPosition)
{
    mSnakeBody.push_front(StartingPosition);
}

position Snake::get_head() const
{
    return mSnakeBody.front();
}

body& Snake::get_body()
{
    return mSnakeBody;
}

size_t Snake::get_size() const
{
    return mSnakeBody.size();
}

bool Snake::is_in_body(const position& Point) const
{
    if (find(mSnakeBody.begin(), mSnakeBody.end(), Point) == mSnakeBody.end())
        return false;

    else
        return true;
}

void Snake::update_position(position NewHeadPosition)
{
    mSnakeBody.push_front(NewHeadPosition);
    mSnakeBody.pop_back();

    return;
}

void Snake::insert_new_head(position NewHeadPosition)
{
    mSnakeBody.push_front(NewHeadPosition);

    return;
}