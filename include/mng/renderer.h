#ifndef MNG_RENDERER_H
#define MNG_RENDERER_H

#include <mng/vector2.h>
#include <mng/texture.h>
#include <mng/window.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct DrawTextureParameters {
    Rect region;
    Point position;
    Vector2 scale;
    float rotation;
    Point origin;
} DrawTextureParameters;

DrawTextureParameters make_draw_texture_parameters();

typedef struct Renderer Renderer;

Renderer* renderer_new(Window* window);
void renderer_free(Renderer* renderer);

void renderer_set_clear_color(Renderer* renderer, Color color);
void renderer_set_draw_color(Renderer* renderer, Color color);

void renderer_fill_rect(Renderer* renderer, Rect rect);

void renderer_draw_texture(Renderer* renderer, Texture* texture, DrawTextureParameters parameters);

void renderer_clear(Renderer* renderer);
void renderer_present(Renderer* renderer);

#ifdef __cplusplus
}
#endif

#endif /* MNG_RENDERER_H */
