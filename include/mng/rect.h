#ifndef MNG_RECT_H
#define MNG_RECT_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

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

#endif /* MNG_RECT_H */
