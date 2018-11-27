#ifndef MNG_ENGINE_CORE_H
#define MNG_ENGINE_CORE_H

#include <stdbool.h>

#include <mng/window.h>
#include <mng/renderer.h>
#include <mng/engine.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Engine {
    bool running;
    double update_delta;
    double fixed_update_delta;
    double now_time;
    double last_time;
    double fixed_time_counter;
    EngineSettings settings;
    Game game;
    Window* window;
    Renderer* renderer;
} Engine;


extern Engine engine;

void engine_initialize(void);
void engine_initialize_libraries(void);
void engine_initialize_window(void);
void engine_initialize_renderer(void);
void engine_finalize(void);
void engine_finalize_libraries(void);
void engine_finalize_window(void);
void engine_finalize_renderer(void);

void engine_quit(void);

void engine_begin_loop(void);
void engine_process_events(void);
void engine_update(void);
void engine_render(void);

#ifdef __cplusplus
}
#endif

#endif /* MNG_ENGINE_CORE_H */
