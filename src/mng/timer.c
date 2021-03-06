#include <mng/timer.h>

#include <SDL_timer.h>

uint32_t timer_get_ticks_in_milliseconds(void)
{
    return SDL_GetTicks();
}

double timer_get_ticks_in_seconds(void)
{
    return timer_get_ticks_in_milliseconds() / 1000.0;
}

uint32_t timer_highres_get_ticks_in_milliseconds(void)
{
    return timer_highres_get_ticks_in_seconds() * 1000;
}

double timer_highres_get_ticks_in_seconds(void)
{
    return SDL_GetPerformanceCounter() / (double)SDL_GetPerformanceFrequency();
}
