/* ADT for a generic graphics interface */

#ifndef GRAPHICS
#define GRAPHICS

template <class Environment>

class Graphics
{
    public:

    virtual void draw_screen(const Environment& CurrentEnvironment) const = 0;
    virtual void handle_off_screen_limits(const Environment& CurrentEnvironment) = 0;
};

#endif