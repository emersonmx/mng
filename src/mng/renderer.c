#include <mng/renderer.h>

#include <mng/macros.h>
#include <mng/texture_impl.h>
#include <mng/window_impl.h>
#include <mng/renderer_impl.h>

void set_render_draw_color(Renderer* renderer, Color color)
{
    int red = color.red * 255;
    int green = color.green * 255;
    int blue = color.blue * 255;
    int alpha = color.alpha * 255;
    SDL_SetRenderDrawColor(renderer->handler, red, green, blue, alpha);
}

Renderer* renderer_new(Window* window)
{
    ASSERT_VALID_OBJECT(window);

    Renderer* renderer = malloc(sizeof(Renderer));
    RETURN_VALUE_IF_NULL(renderer, NULL);

    renderer->window = window;
    renderer->handler = NULL;
    renderer->clear_color = (Color){0.0f, 0.0f, 0.0f, 1.0f};
    renderer->vsync = false;

    return renderer;
}

void renderer_free(Renderer* renderer)
{
    RETURN_IF_NULL(renderer);
    renderer_destroy(renderer);
    free(renderer);
}

void renderer_create(Renderer* renderer)
{
    ASSERT_VALID_OBJECT(renderer);

    renderer_destroy(renderer);

    Uint32 flags = SDL_RENDERER_ACCELERATED;
    if (renderer->vsync) {
        flags |= SDL_RENDERER_PRESENTVSYNC;
    }

    Window* window = renderer->window;
    renderer->handler = SDL_CreateRenderer(window->handler, -1, flags);
    RETURN_IF_NULL(renderer->handler);

    SDL_SetRenderDrawBlendMode(renderer->handler, SDL_BLENDMODE_BLEND);
}

void renderer_destroy(Renderer* renderer)
{
    ASSERT_VALID_OBJECT(renderer);
    SDL_DestroyRenderer(renderer->handler);
    renderer->handler = NULL;
}

bool renderer_was_created(Renderer* renderer)
{
    ASSERT_VALID_OBJECT(renderer);
    return renderer->handler != NULL;
}

Color renderer_get_clear_color(Renderer* renderer)
{
    ASSERT_VALID_OBJECT(renderer);
    return renderer->clear_color;
}

void renderer_set_clear_color(Renderer* renderer, Color color)
{
    ASSERT_VALID_OBJECT(renderer);
    renderer->clear_color = color;
}

Color renderer_get_draw_color(Renderer* renderer)
{
    ASSERT_VALID_OBJECT(renderer);
    RETURN_VALUE_IF_NULL(renderer->handler, renderer->draw_color);

    Uint8 r, g, b, a;
    SDL_GetRenderDrawColor(renderer->handler, &r, &g, &b, &a);
    return (Color){
        .red = r/255.0f, .green = g/255.0f, .blue = b/255.0f, .alpha = a/255.0f
    };
}

void renderer_set_draw_color(Renderer* renderer, Color color)
{
    ASSERT_VALID_OBJECT(renderer);
    renderer->draw_color = color;
    RETURN_IF_NULL(renderer->handler);
}

bool renderer_has_vsync(Renderer* renderer)
{
    ASSERT_VALID_OBJECT(renderer);
    return renderer->vsync;
}

void renderer_set_vsync(Renderer* renderer, bool vsync)
{
    ASSERT_VALID_OBJECT(renderer);
    renderer->vsync = vsync;
}

void renderer_draw_point2(Renderer* renderer, Point2 point)
{
    ASSERT_VALID_OBJECT(renderer);
    RETURN_IF_NULL(renderer->handler);

    set_render_draw_color(renderer, renderer->draw_color);
    SDL_RenderDrawPoint(renderer->handler, point.x, point.y);
}

void renderer_draw_line2(Renderer* renderer, Line2 line)
{
    ASSERT_VALID_OBJECT(renderer);
    RETURN_IF_NULL(renderer->handler);

    set_render_draw_color(renderer, renderer->draw_color);
    SDL_RenderDrawLine(renderer->handler,
        line.start.x, line.start.y,
        line.end.x, line.end.y
    );
}

void renderer_fill_rect(Renderer* renderer, Rect rect)
{
    ASSERT_VALID_OBJECT(renderer);
    RETURN_IF_NULL(renderer->handler);

    set_render_draw_color(renderer, renderer->draw_color);
    SDL_Rect r = {rect.x, rect.y, rect.width, rect.height};
    SDL_RenderFillRect(renderer->handler, &r);
}

void renderer_draw_sprite(Renderer* renderer, Sprite* sprite)
{
    ASSERT_VALID_OBJECT(renderer);
    RETURN_IF_NULL(renderer->handler);
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
    RETURN_IF_NULL(renderer->handler);

    set_render_draw_color(renderer, renderer->clear_color);
    SDL_RenderClear(renderer->handler);
}

void renderer_present(Renderer* renderer)
{
    ASSERT_VALID_OBJECT(renderer);
    RETURN_IF_NULL(renderer->handler);

    SDL_RenderPresent(renderer->handler);
}

