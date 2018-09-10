#include <mng/renderstate.h>

RenderState renderstate_reseted()
{
    return (RenderState){
        (Rect){0, 0, 0, 0},
        (Point){0, 0},
        (Vector2){1.0f, 1.0f},
        0.0f,
        (Point){0, 0}
    };
}
