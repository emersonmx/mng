#ifndef MNG_RENDERER_H
#define MNG_RENDERER_H

#include <mng/sprite.h>
#include <mng/window.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Renderer Renderer;

Renderer* renderer_new(Window* window);
void renderer_free(Renderer* renderer);

void renderer_set_clear_color(Renderer* renderer, Color color);
void renderer_set_draw_color(Renderer* renderer, Color color);

void renderer_draw_point(Renderer* renderer, Point point);
void renderer_draw_line(Renderer* renderer, Line line);
void renderer_fill_rect(Renderer* renderer, Rect rect);

void renderer_draw_sprite(Renderer* renderer, Sprite* sprite);

void renderer_clear(Renderer* renderer);
void renderer_present(Renderer* renderer);

#ifdef __cplusplus
}
#endif

#endif /* MNG_RENDERER_H */
