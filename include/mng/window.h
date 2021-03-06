#ifndef MNG_WINDOW_H
#define MNG_WINDOW_H

#include <stdbool.h>

#include <mng/point2.h>
#include <mng/size.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Window Window;


Window* window_new(void);
void window_free(Window* window);

bool window_was_created(Window* window);
const char* window_get_title(Window* window);
void window_set_title(Window* window, const char* title);
Point2 window_get_position(Window* window);
void window_set_position(Window* window, Point2 position);
void window_center_position(Window* window);
Size window_get_size(Window* window);
void window_set_size(Window* window, Size size);
bool window_is_resizable(Window* window);
void window_set_resizable(Window* window, bool resizable);
bool window_is_fullscreen(Window* window);
void window_set_fullscreen(Window* window, bool fullscreen);

void window_create(Window* window);
void window_destroy(Window* window);

#ifdef __cplusplus
}
#endif

#endif /* MNG_WINDOW_H */
