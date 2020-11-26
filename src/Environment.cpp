#include <ctime>    // time()
#include <cstdlib>  // rand()


#include "Environment.h"

const position StartingPosition = std::make_pair(0,0);
const direction StartingDirection = std::make_pair(1, 0);

Environment::Environment():
mEnvHeight(30),
mEnvWidth(30), 
mSnake(StartingPosition),
mMovDirection(StartingDirection) 
{
    srand(time(NULL));  // seed for rand()
    generate_food(1);
}

Environment::Environment(int EnvHeight, int EnvWidth):
mEnvHeight(EnvHeight),
mEnvWidth(EnvWidth),
mSnake(StartingPosition),
mMovDirection(StartingDirection)
{
    srand(time(NULL));  // seed for rand()
    generate_food(1);
}

int Environment::get_environment_width() const
{
    return mEnvWidth;
}

int Environment::get_environment_height() const
{
    return mEnvHeight;
}

direction Environment::get_mov_direction()
{
    return mMovDirection;
}

body& Environment::get_snake_body()
{
    return mSnake.get_body();
}

food_location& Environment::get_food_location()
{
    return mFoodLocation;
}

size_t Environment::get_score()
{
    return mSnake.get_size() - 1;
}

void Environment::set_mov_direction(direction NewDirection)
{
    // makes sure that the snake can't move "backwards",
    // e.g. move right->left, up->down, etc
    
    // prevents the sequence (1, 0) and (-1, 0) (UP and DOWN)
    if (mMovDirection.first * NewDirection.first == -1)
        return;

    // prevents the sequence (0,1) and (0,-1) (LEFT and RIGHT)
    else if (mMovDirection.second * NewDirection.second == -1)
        return;
    
    else
        mMovDirection = NewDirection;
}

void Environment::generate_food(const int& Amount)
{
    for (int i = 0; i < Amount; i++)
    {
        position RandomPosition;

        while(true)
        {
            int RandY = rand() % mEnvHeight;
            int RandX = rand() % mEnvWidth;

            RandomPosition = std::make_pair(RandY, RandX);

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

STATUS Environment::update_environment()
{
    position CurrentHead = mSnake.get_head();
    position NextHead;

    NextHead.first = CurrentHead.first + mMovDirection.first;
    NextHead.second = CurrentHead.second + mMovDirection.second;

    // handle snake leaving screen borders
    if (NextHead.first >= mEnvHeight)
        NextHead.first -= mEnvHeight;

    else if (NextHead.first < 0)
        NextHead.first += mEnvHeight;


    if (NextHead.second >= mEnvWidth)
        NextHead.second -= mEnvWidth;

    else if (NextHead.second < 0)
        NextHead.second += mEnvWidth;

    // handle collision with the body
    if (mSnake.is_in_body(NextHead))
        return GAME_OVER;

    // handle food collision
    auto p = std::find(mFoodLocation.begin(), mFoodLocation.end(), NextHead);
    
    if (p != mFoodLocation.end())
    {
        mSnake.insert_new_head(NextHead);
        mFoodLocation.erase(p);
        generate_food(1);
        return GAME_ONGOING;
    }

    mSnake.update_position(NextHead);
    return GAME_ONGOING;
}