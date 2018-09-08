#include <mng/renderer.h>

#include <mng/macros.h>
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

