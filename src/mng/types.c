#include <mng/types.h>

Vector2 size_to_vector2(Size size)
{
    return (Vector2){size.width, size.height};
}

bool rect_is_empty(Rect rect) {
    return rect.width <= 0 || rect.height <= 0;
}
