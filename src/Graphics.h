/*

This creates a 60x60 "window" on a terminal

*/

#ifndef GRAPHICS
#define GRAPHICS

#include "Environment.h"
#include <cstdio>

class Graphics
{
    private:

    const static int mWidth =  30, mHeight = 10;
    char mScreen[mHeight+2][mWidth+2];

    public:

    Graphics();
    void refresh_buffer();
    void draw_screen(const Environment& CurrentEnvironment);
};

#endif