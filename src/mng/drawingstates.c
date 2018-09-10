#include <mng/drawingstates.h>

DrawingStates drawingstates_reseted()
{
    return (DrawingStates){
        (Rect){0, 0, 0, 0},
        (Point){0, 0},
        (Vector2){1.0f, 1.0f},
        0.0f,
        (Point){0, 0}
    };
}
