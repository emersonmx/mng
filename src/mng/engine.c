#include <mng/engine.h>

#include <stdbool.h>

#include <mng/timer.h>
#include <mng/window.h>
#include <mng/renderer.h>

typedef struct EngineContext {
    bool running;
    double update_delta;
    double fixed_update_delta;
    Window* window;
    Renderer* renderer;
} EngineContext;

static EngineContext context = {
    .running = true,
    .update_delta = 0.0
};

void engine_initialize(void)
{
    context.fixed_update_delta = 1/60.0;
}

void engine_finalize(void)
{

}

void engine_run(Game game)
{
    engine_initialize();

    game.init();

    double fixed_time_counter = 0.0;
    double last_count = timer_highres_get_ticks_in_seconds();

    while (context.running) {
        double now = timer_highres_get_ticks_in_seconds();
        context.update_delta = now - last_count;
        last_count = now;
        fixed_time_counter += context.update_delta;

        InputEvent event;
        game.input(&event);

        if (fixed_time_counter >= context.fixed_update_delta) {
            game.fixed_update(context.fixed_update_delta);
            fixed_time_counter -= context.fixed_update_delta;
        }

        game.update(context.update_delta);

        game.render();
    }

    game.quit();

    engine_finalize();
}
