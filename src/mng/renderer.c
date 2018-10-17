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

    SDL_SetRenderDrawBlendMode(renderer->handler, SDL_BLENDMODE_BLEND);

    renderer->clear_color = (Color){0, 0, 0, 255};

    return renderer;
}

void renderer_free(Renderer* renderer)
{
    RETURN_IF_NULL(renderer);
    SDL_DestroyRenderer(renderer->handler);
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

void renderer_draw_point(Renderer* renderer, Point point)
{
    ASSERT_VALID_OBJECT(renderer);
    SDL_RenderDrawPoint(renderer->handler, point.x, point.y);
}

void renderer_draw_line(Renderer* renderer, Line line)
{
    ASSERT_VALID_OBJECT(renderer);
    SDL_RenderDrawLine(renderer->handler,
        line.start.x, line.start.y,
        line.end.x, line.end.y
    );
}

void renderer_fill_rect(Renderer* renderer, Rect rect)
{
    ASSERT_VALID_OBJECT(renderer);
    SDL_Rect r = {rect.x, rect.y, rect.width, rect.height};
    SDL_RenderFillRect(renderer->handler, &r);
}

void renderer_draw_sprite(Renderer* renderer, Sprite* sprite)
{
    ASSERT_VALID_OBJECT(renderer);
    RETURN_IF_NULL(sprite);
    RETURN_IF_NULL(sprite->texture);

    double angle = sprite->rotation;
    SDL_Point center = {
        sprite->origin.x * fabsf(sprite->scale.x),
        sprite->origin.y * fabsf(sprite->scale.y)
    };

    SDL_Rect srcrect = {
        sprite->region.x, sprite->region.y,
        sprite->region.width, sprite->region.height
    };
    SDL_Rect dstrect = {
        sprite->position.x - center.x,
        sprite->position.y - center.y,
        sprite->texture->size.width * fabsf(sprite->scale.x),
        sprite->texture->size.height * fabsf(sprite->scale.y)
    };

    SDL_RendererFlip flip = SDL_FLIP_NONE;
    if (sprite->scale.x < 0.0) {
        flip = flip | SDL_FLIP_HORIZONTAL;
    }
    if (sprite->scale.y < 0.0) {
        flip = flip | SDL_FLIP_VERTICAL;
    }

    SDL_RenderCopyEx(
        renderer->handler, sprite->texture->handler,
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

