#ifndef MNG_ENGINE_H
#define MNG_ENGINE_H

#include <mng/game.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct EngineSettings {
    int wip;
} EngineSettings;

void engine_load_settings(EngineSettings* settings);
void engine_run(Game game);

#ifdef __cplusplus
}
#endif

#endif /* MNG_ENGINE_H */
