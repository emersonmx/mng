#ifndef EXAMPLES_PONG_APP_H
#define EXAMPLES_PONG_APP_H

#include <mng/color.h>
#include <mng/line.h>
#include <mng/point.h>
#include <mng/rect.h>
#include <mng/size.h>
#include <mng/window.h>
#include <mng/renderer.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct App App;


App* app_new(void);
void app_free(App* app);

Window* app_get_window(App* app);
int app_get_physics_fps(App* app);
void app_set_physics_fps(App* app, int fps);
double app_get_physics_process_delta_time(App* app);

void app_run(App* app);
void app_quit(App* app);

#ifdef __cplusplus
}
#endif

#endif /* EXAMPLES_PONG_APP_H */
