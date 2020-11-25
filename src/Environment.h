/* 
interface connecting the object (snake) to the environment 
TODO: handle edge trespassing
*/

#ifndef ENVIRONMENT
#define ENVIRONMENT

#include "types.h"

#include "Snake.h"

// to spawn food blocks randomly:
#include <ctime>
#include <cstdlib>

enum STATUS
{
    GAME_ONGOING,
    GAME_OVER
};

class Environment
{
    private:
    
    int mEnvWidth;
    int mEnvHeight;

    Snake mSnake;
    food_location mFoodLocation;
    direction mMovDirection;

    // manipulate food
    void generate_food(const int& Amount);

    public:

    Environment();
    Environment(int EnvWidth, int EnvHeight);
    int get_environment_width() const;
    int get_environment_height() const;
    body& get_snake_body();
    food_location& get_food_location();

    void set_mov_direction(direction NewDirection);
    
    STATUS update_environment();
    
};

#endif