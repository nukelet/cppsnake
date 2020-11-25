#include "Environment.h"

const position StartingPosition = std::make_pair(0,0);
const direction StartingDirection = std::make_pair(1, 0);

Environment::Environment():
mEnvWidth(60), 
mEnvHeight(60), 
mSnake(StartingPosition),
mMovDirection(StartingDirection) 
{
    srand(time(NULL));  // seed for rand()
    generate_food(1);
}

Environment::Environment(int EnvWidth, int EnvHeight):
mEnvWidth(EnvWidth), 
mEnvHeight(EnvHeight), 
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

body& Environment::get_snake_body()
{
    return mSnake.get_body();
}

food_location& Environment::get_food_location()
{
    return mFoodLocation;
}

void Environment::set_mov_direction(direction NewDirection)
{
    mMovDirection = NewDirection;
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

STATUS Environment::update_environment()
{
    position CurrentHead = mSnake.get_head();
    position NextHead;

    NextHead.first = CurrentHead.first + mMovDirection.first;
    NextHead.second = CurrentHead.second + mMovDirection.second;

    // handle snake leaving screen borders
    if (NextHead.first > mEnvWidth)
        NextHead.first %= mEnvWidth;

    if (NextHead.second > mEnvHeight)
        NextHead.second %= mEnvHeight;

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