#include <mng/renderstates.h>

RenderStates renderstates_reseted()
{
    return (RenderStates){
        (Rect){0, 0, 0, 0},
        (Point){0, 0},
        (Vector2){1.0f, 1.0f},
        0.0f,
        (Point){0, 0}
    };
}
