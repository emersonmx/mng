#ifndef MNG_WINDOW_IMPL_H
#define MNG_WINDOW_IMPL_H

#include <stdbool.h>

#include <SDL_video.h>

#include <mng/point2.h>
#include <mng/size.h>

struct Window {
    SDL_Window* handler;
    const char* title;
    Point2 position;
    Size size;
    bool resizable;
    bool fullscreen;
};

#endif /* MNG_WINDOW_IMPL_H */
