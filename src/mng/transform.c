#include <mng/transform.h>

Transform transform_reseted()
{
    return (Transform){
        (Vector2){0.0f, 0.0f},
        (Vector2){1.0f, 1.0f},
        0.0f,
        (Vector2){0.0f, 0.0f},
    };
}
