#ifndef MNG_TYPES_H
#define MNG_TYPES_H

#include <stdbool.h>
#include <stdint.h>

#include <mng/vector2.h>
#include <mng/point.h>
#include <mng/line.h>
#include <mng/color.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Size {
    int width;
    int height;
} Size;


Vector2 size_to_vector2(Size size);

typedef struct Rect {
    int x;
    int y;
    int width;
    int height;
} Rect;


bool rect_is_empty(Rect rect);

#ifdef __cplusplus
}
#endif

#endif /* MNG_TYPES_H */
