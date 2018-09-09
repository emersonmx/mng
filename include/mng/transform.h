#ifndef MNG_TRANSFORM_H
#define MNG_TRANSFORM_H

#include <mng/vector2.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Transform {
    Vector2 position;
    Vector2 scale;
    float rotation;
    Vector2 origin;
} Transform;

Transform transform_reseted();

#ifdef __cplusplus
}
#endif

#endif /* MNG_TRANSFORM_H */
