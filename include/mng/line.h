#ifndef MNG_LINE_H
#define MNG_LINE_H

#include <mng/point2.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Line {
    Point2 start;
    Point2 end;
} Line;

#ifdef __cplusplus
}
#endif

#endif /* MNG_LINE_H */
