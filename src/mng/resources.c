#include <mng/resources.h>

#include <SDL_image.h>

#include <mng/macros.h>
#include <mng/texture_impl.h>
#include <mng/renderer_impl.h>

Texture* load_texture(Renderer* renderer, const char* filename)
{
    SDL_Surface* loadedSurface = IMG_Load(filename);
    RETURN_VALUE_IF_NULL(loadedSurface, NULL);

    Size size = {loadedSurface->w, loadedSurface->h};

    SDL_Texture* newTexture = SDL_CreateTextureFromSurface(renderer->handler, loadedSurface);
    RETURN_VALUE_IF_NULL(newTexture, NULL);

    SDL_FreeSurface(loadedSurface);

    Texture* texture = texture_new();
    if (texture == NULL) {
        SDL_DestroyTexture(newTexture);
        return NULL;
    }

    texture->handler = newTexture;
    texture->size = size;
    return texture;
}
