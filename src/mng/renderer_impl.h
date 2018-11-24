#ifndef MNG_RENDERER_IMPL_H
#define MNG_RENDERER_IMPL_H

#include <SDL_render.h>

#include <mng/color.h>

struct Renderer {
    SDL_Renderer* handler;
    Color clear_color;
};

#endif /* MNG_RENDERER_IMPL_H */
