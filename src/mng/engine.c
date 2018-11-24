#include <mng/engine.h>

#include <stdbool.h>

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
    .running = true
};

void engine_initialize(void)
{

}

void engine_finalize(void)
{

}

void engine_run(Game game)
{
    engine_initialize();

    game.init();

    while (context.running) {
        InputEvent event;
        game.input(&event);
        game.fixed_update(context.fixed_update_delta);
        game.update(context.update_delta);
        game.render();
    }

    game.quit();

    engine_finalize();
}
