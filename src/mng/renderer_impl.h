#ifndef MNG_RENDERER_IMPL_H
#define MNG_RENDERER_IMPL_H

#include <stdbool.h>

#include <SDL_render.h>

#include <mng/color.h>
#include <mng/window_impl.h>

struct Renderer {
    Window* window;
    SDL_Renderer* handler;
    Color clear_color;
    Color draw_color;
    bool vsync;
};

#endif /* MNG_RENDERER_IMPL_H */
