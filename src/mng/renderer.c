#include <mng/renderer.h>

#include <stdio.h>

#include <mng/macros.h>
#include <mng/texture_impl.h>
#include <mng/window_impl.h>
#include <mng/renderer_impl.h>

Renderer* renderer_new(Window* window)
{
    ASSERT_VALID_OBJECT(window);

    Renderer* renderer = malloc(sizeof(Renderer));
    RETURN_VALUE_IF_NULL(renderer, NULL);

    renderer->handler = SDL_CreateRenderer(window->handler, -1, SDL_RENDERER_ACCELERATED);
    RETURN_VALUE_IF_NULL(renderer->handler, NULL);

    renderer->clear_color = (Color){0, 0, 0, 255};

    return renderer;
}

void renderer_free(Renderer* renderer)
{
    RETURN_IF_NULL(renderer);
    SDL_DestroyRenderer(renderer->handler);
    renderer->handler = NULL;
    free(renderer);
}

void renderer_set_clear_color(Renderer* renderer, Color color)
{
    ASSERT_VALID_OBJECT(renderer);
    renderer->clear_color = color;
}

void renderer_set_draw_color(Renderer* renderer, Color color)
{
    ASSERT_VALID_OBJECT(renderer);
    SDL_SetRenderDrawColor(renderer->handler, color.red, color.green, color.blue, color.alpha);
}

void renderer_fill_rect(Renderer* renderer, Rect rect)
{
    ASSERT_VALID_OBJECT(renderer);
    SDL_Rect r = {rect.x, rect.y, rect.width, rect.height};
    SDL_RenderFillRect(renderer->handler, &r);
}

void renderer_draw_texture(Renderer* renderer, Texture* texture, Transform transform)
{
    ASSERT_VALID_OBJECT(renderer);
    RETURN_IF_NULL(texture);
    RETURN_IF_NULL(texture->handler);

    double angle = transform.rotation;
    SDL_Point center = {
        transform.origin.x * fabsf(transform.scale.x),
        transform.origin.y * fabsf(transform.scale.y)
    };

    SDL_Rect srcrect = {
        0, 0,
        texture->size.width,
        texture->size.height
    };
    SDL_Rect dstrect = {
        transform.position.x - center.x,
        transform.position.y - center.y,
        texture->size.width * fabsf(transform.scale.x),
        texture->size.height * fabsf(transform.scale.y)
    };

    SDL_RendererFlip flip = SDL_FLIP_NONE;
    if (transform.scale.x < 0) {
        flip = flip | SDL_FLIP_HORIZONTAL;
    }
    if (transform.scale.y < 0) {
        flip = flip | SDL_FLIP_VERTICAL;
    }

    SDL_RenderCopyEx(
        renderer->handler, texture->handler,
        &srcrect, &dstrect,
        angle, &center, flip
    );
}

void renderer_clear(Renderer* renderer)
{
    ASSERT_VALID_OBJECT(renderer);
    renderer_set_draw_color(renderer, renderer->clear_color);
    SDL_RenderClear(renderer->handler);
}

void renderer_present(Renderer* renderer)
{
    ASSERT_VALID_OBJECT(renderer);
    SDL_RenderPresent(renderer->handler);
}

