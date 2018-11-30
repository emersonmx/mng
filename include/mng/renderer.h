#ifndef MNG_RENDERER_H
#define MNG_RENDERER_H

#include <mng/color.h>
#include <mng/line2.h>
#include <mng/point2.h>
#include <mng/rect.h>
#include <mng/sprite.h>
#include <mng/window.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Renderer Renderer;


Renderer* renderer_new(Window* window);
void renderer_free(Renderer* renderer);

void renderer_create(Renderer* renderer);
void renderer_destroy(Renderer* renderer);

Color renderer_get_clear_color(Renderer* renderer);
void renderer_set_clear_color(Renderer* renderer, Color color);
Color renderer_get_draw_color(Renderer* renderer);
void renderer_set_draw_color(Renderer* renderer, Color color);
bool renderer_has_vsync(Renderer* renderer);
void renderer_set_vsync(Renderer* renderer, bool vsync);

void renderer_draw_point2(Renderer* renderer, Point2 point);
void renderer_draw_line2(Renderer* renderer, Line2 line);
void renderer_fill_rect(Renderer* renderer, Rect rect);

void renderer_draw_sprite(Renderer* renderer, Sprite* sprite);

void renderer_clear(Renderer* renderer);
void renderer_present(Renderer* renderer);

#ifdef __cplusplus
}
#endif

#endif /* MNG_RENDERER_H */
