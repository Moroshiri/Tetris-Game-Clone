#ifndef _TIME_HPP_
#define _TIME_HPP_

#include <SDL2/SDL_timer.h>

class Time
{
public:
    Time();
    ~Time();

    Uint32 DeltaTime;

    void CalculateTime();

private:
    Uint32 _currentFrame, _lastFrame;
};

#endif