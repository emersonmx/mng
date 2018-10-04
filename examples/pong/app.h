#ifndef EXAMPLES_PONG_APP_H
#define EXAMPLES_PONG_APP_H

#include <mng/types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct App App;

App* app_new();
void app_free(App* app);

int app_get_physics_fps(App* app);
void app_set_physics_fps(App* app, int fps);

void app_initialize(App* app);
void app_run(App* app);
void app_finalize(App* app);
void app_quit(App* app);

#ifdef __cplusplus
}
#endif

#endif /* EXAMPLES_PONG_APP_H */
