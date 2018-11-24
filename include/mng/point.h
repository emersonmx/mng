#ifndef MNG_POINT_H
#define MNG_POINT_H

#include <mng/vector2.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Point {
    int x;
    int y;
} Point;

Vector2 point_to_vector2(Point point);

#ifdef __cplusplus
}
#endif

#endif /* MNG_POINT_H */
