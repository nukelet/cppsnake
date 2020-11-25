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

class Environment
{
    private:
    Snake mSnake;
    food_location mFoodLocation;

    const int mEnvWidth;
    const int mEnvHeight;


    public:

    Environment();
    Environment(const int& EnvWidth, const int& EnvHeight);
    int get_environment_width() const;
    int get_environment_height() const;
    body get_snake_body() const;
    food_location get_food_location() const;

    // manipulate food
    bool is_food_location(const position&) const; // TODO: DECIDE HOW TO HANDLE FOOD_LOCATION
    void generate_food(const int& Amount);  // generate food at random locations. maybe generate more food as snake grows bigger?
    // void handle_offscreen();    // handle snake leaving screen limits
    
    // manipulate snake

/*
    void check_food_collision() const;
    void check_edge_collision() const;
    void check_self_collision() const;
*/

    void set_snake_direction(const direction& NewDirection);
    
    bool handle_food_collision();
    bool handle_edge_collision();
    bool handle_self_collision();

    void update_environment();
    
};

#endif