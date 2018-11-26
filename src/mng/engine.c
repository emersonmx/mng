#include <mng/engine.h>

#include <SDL.h>

#include <mng/engine_core.h>
#include <mng/timer.h>

void engine_set_settings(EngineSettings settings)
{
    engine.settings = settings;
}

void engine_run(Game game)
{
    engine.game = game;

    engine_initialize();

    engine.game.init();

    double fixed_time_counter = 0.0;
    double last_count = timer_highres_get_ticks_in_seconds();

    while (engine.running) {
        double now = timer_highres_get_ticks_in_seconds();
        engine.update_delta = now - last_count;
        last_count = now;
        fixed_time_counter += engine.update_delta;

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                engine_quit();
            }

            engine.game.process_event(&event);
        }

        if (fixed_time_counter >= engine.fixed_update_delta) {
            game.fixed_update(engine.fixed_update_delta);
            fixed_time_counter -= engine.fixed_update_delta;
        }

        engine.game.update(engine.update_delta);

        renderer_clear(engine.renderer);
        engine.game.render();
        renderer_present(engine.renderer);
    }

    engine.game.quit();

    engine_finalize();
}
