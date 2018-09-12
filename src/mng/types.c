#include <mng/types.h>

bool rect_is_empty(Rect rect) {
    return rect.width <= 0 || rect.height <= 0;
}
