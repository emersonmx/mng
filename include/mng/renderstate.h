#ifndef MNG_RENDERSTATE_H
#define MNG_RENDERSTATE_H

#include <mng/types.h>
#include <mng/vector2.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct RenderState {
    Rect region;
    Point position;
    Vector2 scale;
    float rotation;
    Point origin;
} RenderState;

RenderState renderstate_reseted();

#ifdef __cplusplus
}
#endif

#endif /* MNG_RENDERSTATE_H */
