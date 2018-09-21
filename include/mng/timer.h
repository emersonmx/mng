#ifndef MNG_TIMER_H
#define MNG_TIMER_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint32_t timer_get_ticks_in_milliseconds();
double timer_get_ticks_in_seconds();

uint32_t timer_highres_get_ticks_in_milliseconds();
double timer_highres_get_ticks_in_seconds();

#ifdef __cplusplus
}
#endif

#endif /* MNG_TIMER_H */
