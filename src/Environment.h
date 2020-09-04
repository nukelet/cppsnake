/* 
interface connecting the object (snake) to the environment 
TODO: handle edge trespassing
*/

#ifndef ENVIRONMENT
#define ENVIRONMENT

#include "types.h"

#include "Snake.h"
#include <random>

class Environment
{
    private:

    Snake mSnake;
    food_location mFoodLocation;


    public:

    void get_snake_body() const;
    void get_food_location() const;

    // manipulate food
    void generate_food();       // generate food at random locations. maybe generate more food as snake grows bigger?
    // void handle_offscreen();    // handle snake leaving screen limits
    
    // manipulate snake

    void handle_food_collision();
    void handle_edge_collision();
    bool has_self_collision();
    
};

#endif