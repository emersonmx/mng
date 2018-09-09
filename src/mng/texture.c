#include <mng/texture.h>

#include <mng/macros.h>
#include <mng/texture_impl.h>

Texture* texture_new()
{
    Texture* texture = malloc(sizeof(Texture));
    RETURN_VALUE_IF_NULL(texture, NULL);

    texture->handler = NULL;

    return texture;
}

void texture_free(Texture* texture)
{
    RETURN_IF_NULL(texture);
    SDL_DestroyTexture(texture->handler);
    texture->handler = NULL;
    free(texture);
}

Size texture_size(Texture* texture)
{
    RETURN_VALUE_IF_NULL(texture, ((Size){0, 0}));
    return texture->size;
}
