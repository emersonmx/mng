#ifndef MNG_ENGINE_H
#define MNG_ENGINE_H

#include <stdbool.h>

#include <mng/point2.h>
#include <mng/size.h>
#include <mng/game.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct WindowSettings {
    const char* title;
    Point2 position;
    bool centered;
    Size size;
    bool resizable;
    bool fullscreen;
} WindowSettings;

typedef struct RendererSettings {
    bool vsync;
} RendererSettings;

typedef struct EngineSettings {
    WindowSettings window;
    RendererSettings renderer;
} EngineSettings;

EngineSettings engine_get_settings(void);
void engine_set_settings(EngineSettings settings);
void engine_run(Game game);

#ifdef __cplusplus
}
#endif

#endif /* MNG_ENGINE_H */
