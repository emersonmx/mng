#ifndef MNG_LINE_H
#define MNG_LINE_H

#include <mng/point.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Line {
    Point start;
    Point end;
} Line;

#ifdef __cplusplus
}
#endif

#endif /* MNG_LINE_H */