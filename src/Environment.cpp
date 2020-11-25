#include "Environment.h"

const position StartingPosition = std::make_pair(0,0);
const direction StartingDirection = std::make_pair(1, 0);

Environment::Environment():

mEnvWidth(60), 
mEnvHeight(60), 
mSnake(StartingPosition, StartingDirection) 
{
    srand(time(NULL));  // seed for rand()
}

Environment::Environment(const int& EnvWidth, const int& EnvHeight):

mEnvWidth(EnvWidth), 
mEnvHeight(EnvHeight), 
mSnake(StartingPosition, StartingDirection) 
{
    srand(time(NULL));  // seed for rand()
}

int Environment::get_environment_width() const
{
    return mEnvWidth;
}

int Environment::get_environment_height() const
{
    return mEnvHeight;
}

body Environment::get_snake_body() const
{
    return mSnake.get_body();
}

food_location Environment::get_food_location() const
{
    return mFoodLocation;
}

void Environment::generate_food(const int& Amount)
{
    for (int i = 0; i < Amount; i++)
    {
        position RandomPosition;

        while(true)
        {
            int RandX = rand() % mEnvWidth;
            int RandY = rand() % mEnvHeight;
            RandomPosition = std::make_pair(RandX, RandY);

            /*
                won't allow generating food positions
                within the snake's body
            */

            if (mSnake.is_in_body(RandomPosition) == false)
            {
                break;
            }
        }

        mFoodLocation.push_back(RandomPosition);
    }
}

bool Environment::is_food_location(const position& Point) const
{
    if (std::find(mFoodLocation.begin(), mFoodLocation.end(), Point) != mFoodLocation.end())
        return true;
    else
        return false;
}

void Environment::set_snake_direction(const direction& NewDirection)
{
    mSnake.set_direction(NewDirection);
}

bool Environment::handle_food_collision()
{
    position NextHead = mSnake.get_next_head();

    if ( !is_food_location(NextHead) )
        return false;

    mSnake.grow_snake(NextHead);
    return true;
}

bool Environment::handle_edge_collision()
{
    position NextHead = mSnake.get_next_head();
    bool flag = false;

    if (NextHead.first < mEnvWidth)
    {
        position NewHeadPosition = std::make_pair(mEnvWidth, NextHead.second);
        mSnake.teleport_head(NewHeadPosition); 
        flag = true;    
    }

    else if (NextHead.first > mEnvWidth)
    {
        position NewHeadPosition = std::make_pair(0, NextHead.second);
        mSnake.teleport_head(NewHeadPosition);
        flag = true;
    }

    if (NextHead.second < mEnvHeight)
    {
        position NewHeadPosition = std::make_pair(NextHead.first, mEnvHeight);
        mSnake.teleport_head(NewHeadPosition);
        flag = true;
    }

    else if (NextHead.second > mEnvHeight)
    {
        position NewHeadPosition = std::make_pair(NextHead.first, 0);
        mSnake.teleport_head(NewHeadPosition);
        flag = true;
    }

    return flag;
}

bool Environment::handle_self_collision()
{
    position NextHead = mSnake.get_next_head();

    if (mSnake.is_in_body(NextHead))

    // TODO: decide what to do here

}

/*

#include <cstdio>

int main()
{
    Environment MyEnvironment;
    MyEnvironment.generate_food(10);

    food_location FoodLocation = MyEnvironment.get_food_location();

    for (auto it = FoodLocation.begin(); it != FoodLocation.end(); ++it)
    {
        printf("(%d, %d)\n", it->first, it->second);
    }

    return 0;

} 

*/