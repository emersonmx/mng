#ifndef MNG_TEXTURE_IMPL_H
#define MNG_TEXTURE_IMPL_H

#include <SDL_render.h>

#include <mng/types.h>

struct Texture {
    SDL_Texture* handler;
    Size size;
};

#endif /* MNG_TEXTURE_IMPL_H */
