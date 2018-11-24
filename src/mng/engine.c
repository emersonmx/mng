#include <mng/engine.h>

#include <stdbool.h>

#include <SDL.h>

#include <mng/timer.h>
#include <mng/window.h>
#include <mng/renderer.h>

typedef struct EngineContext {
    bool running;
    double update_delta;
    double fixed_update_delta;
    EngineSettings* settings;
    Window* window;
    Renderer* renderer;
} EngineContext;

static EngineContext engine = {
    .running = true,
    .update_delta = 0.0
};

void engine_quit(void)
{
    engine.running = false;
}

void engine_initialize(void)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_Log("Couldn't start SDL.\n\tError: %s", SDL_GetError());
        engine_quit();
        return;
    }

    engine.window = window_new("Pong", (Size){640, 480});
    if (engine.window == NULL) {
        SDL_Log("Couldn't create window.\n\tError: %s", SDL_GetError());
        engine_quit();
        return;
    }

    engine.renderer = renderer_new(engine.window);
    if (engine.renderer == NULL) {
        SDL_Log("Couldn't create renderer.\n\tError: %s", SDL_GetError());
        engine_quit();
        return;
    }

    engine.fixed_update_delta = 1/60.0;
}

void engine_finalize(void)
{
    renderer_free(engine.renderer);
    window_free(engine.window);

    SDL_Quit();
}

void engine_load_settings(EngineSettings* settings)
{
    engine.settings = settings;
}

void engine_run(Game game)
{
    engine_initialize();

    game.init();

    double fixed_time_counter = 0.0;
    double last_count = timer_highres_get_ticks_in_seconds();

    while (engine.running) {
        double now = timer_highres_get_ticks_in_seconds();
        engine.update_delta = now - last_count;
        last_count = now;
        fixed_time_counter += engine.update_delta;

        InputEvent event;
        game.input(&event);

        if (fixed_time_counter >= engine.fixed_update_delta) {
            game.fixed_update(engine.fixed_update_delta);
            fixed_time_counter -= engine.fixed_update_delta;
        }

        game.update(engine.update_delta);

        game.render();
    }

    game.quit();

    engine_finalize();
}
