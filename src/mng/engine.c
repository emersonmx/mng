#include <mng/engine.h>

#include <SDL.h>

#include <mng/engine_core.h>

void engine_set_settings(EngineSettings settings)
{
    engine.settings = settings;
}

void engine_run(Game game)
{
    engine.game = game;

    engine_initialize();

    while (engine.running) {
        engine_begin_loop();
        engine_process_events();
        engine_update();
        engine_render();
    }

    engine_finalize();
}
