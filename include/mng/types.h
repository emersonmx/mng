#ifndef MNG_TYPES_H
#define MNG_TYPES_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct Color {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
} Color;

typedef struct Size {
    int width;
    int height;
} Size;

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
