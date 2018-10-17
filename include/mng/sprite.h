#ifndef MNG_SPRITE_H
#define MNG_SPRITE_H

#include <mng/vector2.h>
#include <mng/types.h>
#include <mng/texture.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Sprite {
    Texture* texture;
    Rect region;
    Point position;
    Vector2 scale;
    double rotation;
    Point origin;
} Sprite;


Sprite* sprite_new(void);
void sprite_free(Sprite* sprite);

#ifdef __cplusplus
}
#endif

#endif /* MNG_SPRITE_H */
