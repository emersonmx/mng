#ifndef MNG_WINDOW_H
#define MNG_WINDOW_H

#include <mng/point2.h>
#include <mng/size.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Window Window;


Window* window_new(void);
void window_free(Window* window);

const char* window_get_title(Window* window);
void window_set_title(Window* window, const char* title);
Point2 window_get_position(Window* window);
void window_set_position(Window* window, const Point2 position);
void window_center_position(Window* window);
Size window_get_size(Window* window);
void window_set_size(Window* window, const Size size);

#ifdef __cplusplus
}
#endif

#endif /* MNG_WINDOW_H */
