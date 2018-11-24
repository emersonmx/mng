#ifndef MNG_POINT2_H
#define MNG_POINT2_H

#include <mng/vector2.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Point2 {
    int x;
    int y;
} Point2;


Vector2 point2_to_vector2(Point2 point);

#ifdef __cplusplus
}
#endif

#endif /* MNG_POINT2_H */
