#include <mng/engine_core.h>

#include <SDL.h>

#include <mng/timer.h>

Engine engine = {
    .running = true,
    .update_delta = 0.0
};

void engine_initialize(void)
{
    engine_initialize_libraries();
    engine_initialize_window();
    engine_initialize_renderer();

    engine.fixed_update_delta = 1/60.0;
    engine.fixed_time_counter = 0.0;
    engine.last_time = timer_highres_get_ticks_in_seconds();

    engine.game.init();
}

void engine_initialize_libraries(void)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_Log("Couldn't start SDL.\n\tError: %s", SDL_GetError());
        engine_quit();
        return;
    }
}

void engine_initialize_window(void)
{
    engine.window = window_new();
    if (engine.window == NULL) {
        SDL_Log("Couldn't create window.\n\tError: %s", SDL_GetError());
        engine_quit();
        return;
    }

    window_set_title(engine.window, engine.settings.window.title);
    window_set_position(engine.window, engine.settings.window.position);
    if (engine.settings.window.centered) {
        window_center_position(engine.window);
    }
    window_set_size(engine.window, engine.settings.window.size);
    window_set_resizable(engine.window, engine.settings.window.resizable);
    window_set_fullscreen(engine.window, engine.settings.window.fullscreen);

    window_create(engine.window);
}

void engine_initialize_renderer(void)
{
    engine.renderer = renderer_new(engine.window);
    if (engine.renderer == NULL) {
        SDL_Log("Couldn't create renderer.\n\tError: %s", SDL_GetError());
        engine_quit();
        return;
    }

    renderer_set_vsync(engine.renderer, engine.settings.renderer.vsync);

    renderer_create(engine.renderer);
}

void engine_finalize(void)
{
    engine.game.quit();

    engine_finalize_renderer();
    engine_finalize_window();
    engine_finalize_libraries();
}

void engine_finalize_libraries(void)
{
    SDL_Quit();
}

void engine_finalize_window(void)
{
    window_free(engine.window);
}

void engine_finalize_renderer(void)
{
    renderer_free(engine.renderer);
}

void engine_quit(void)
{
    engine.running = false;
}

void engine_begin_loop(void)
{
    engine.now_time = timer_highres_get_ticks_in_seconds();
    engine.update_delta = engine.now_time - engine.last_time;
    engine.last_time = engine.now_time;
    engine.fixed_time_counter += engine.update_delta;
}

void engine_process_events(void)
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            engine_quit();
        }

        engine.game.process_event(&event);
    }
}

void engine_update(void)
{
    if (engine.fixed_time_counter >= engine.fixed_update_delta) {
        engine.game.fixed_update(engine.fixed_update_delta);
        engine.fixed_time_counter -= engine.fixed_update_delta;
    }

    engine.game.update(engine.update_delta);
}

void engine_render(void)
{
    renderer_clear(engine.renderer);
    engine.game.render();
    renderer_present(engine.renderer);
}
