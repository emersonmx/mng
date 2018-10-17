#ifndef MNG_TIMER_H
#define MNG_TIMER_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint32_t timer_get_ticks_in_milliseconds(void);
double timer_get_ticks_in_seconds(void);

uint32_t timer_highres_get_ticks_in_milliseconds(void);
double timer_highres_get_ticks_in_seconds(void);

#ifdef __cplusplus
}
#endif

#endif /* MNG_TIMER_H */
