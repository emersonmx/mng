#ifndef MNG_RENDERSTATES_H
#define MNG_RENDERSTATES_H

#include <mng/types.h>
#include <mng/vector2.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct RenderStates {
    Rect region;
    Point position;
    Vector2 scale;
    float rotation;
    Point origin;
} RenderStates;

RenderStates renderstates_reseted();

#ifdef __cplusplus
}
#endif

#endif /* MNG_RENDERSTATES_H */
