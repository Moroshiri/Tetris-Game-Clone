#include "Time.hpp"

Time::Time()
{
    DeltaTime = 0;
}

Time::~Time()
{

}

void Time::CalculateTime()
{
    _currentFrame = SDL_GetTicks();
    DeltaTime = _currentFrame - _lastFrame;
    _lastFrame = _currentFrame;
}