#ifndef MNG_COLOR_H
#define MNG_COLOR_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Color {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
} Color;

#ifdef __cplusplus
}
#endif

#endif /* MNG_COLOR_H */
