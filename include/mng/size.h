#ifndef MNG_SIZE_H
#define MNG_SIZE_H

#include <mng/vector2.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Size {
    int width;
    int height;
} Size;


Vector2 size_to_vector2(Size size);

#ifdef __cplusplus
}
#endif

#endif /* MNG_SIZE_H */
