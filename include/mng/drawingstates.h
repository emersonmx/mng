#ifndef MNG_DRAWINGSTATES_H
#define MNG_DRAWINGSTATES_H

#include <mng/types.h>
#include <mng/vector2.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct DrawingStates {
    Rect region;
    Point position;
    Vector2 scale;
    float rotation;
    Point origin;
} DrawingStates;

DrawingStates drawingstates_reseted();

#ifdef __cplusplus
}
#endif

#endif /* MNG_DRAWINGSTATES_H */
