#ifndef MNG_WINDOW_H
#define MNG_WINDOW_H

#include <mng/size.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Window Window;


Window* window_new(void);
void window_free(Window* window);

Size window_get_size(Window* window);

#ifdef __cplusplus
}
#endif

#endif /* MNG_WINDOW_H */
