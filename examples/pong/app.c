#include "app.h"

#include <stdio.h>
#include <stdbool.h>

#include <SDL.h>

#include <mng/macros.h>
#include <mng/timer.h>
#include <mng/window.h>
#include <mng/renderer.h>

#include "ball.h"
#include "debugger.h"

struct App {
    bool running;
    Window* window;
    Renderer* renderer;
    int physics_fps;
    double ms_per_update;
    double delta;

    Ball* ball;
    Debugger* debugger;
};

void app_ready(App* app)
{
    app->ball = ball_new();
    ball_ready(app->ball);

    app->debugger = debugger_new(app);
    debugger_ready(app->debugger);
}

void app_process_input(App* app, SDL_Event* event)
{
    if (event->type == SDL_QUIT) {
        app_quit(app);
    }
}

void app_physics_process(App* app)
{
    ball_physics_update(app->ball);
}

void app_update(App* app)
{
    ball_update(app->ball);
}

void app_render(App* app)
{
    renderer_clear(app->renderer);
    ball_render(app->ball, app->renderer);

    debugger_render(app->debugger, app->renderer);
    renderer_present(app->renderer);
}

App* app_new()
{
    App* app = malloc(sizeof(App));
    RETURN_VALUE_IF_NULL(app, NULL);

    app->running = true;
    app->window = NULL;
    app->renderer = NULL;
    app_set_physics_fps(app, 60);

    return app;
}

void app_free(App* app)
{
    RETURN_IF_NULL(app);
    free(app);
}

int app_get_physics_fps(App* app)
{
    ASSERT_VALID_OBJECT(app);
    return app->physics_fps;
}

void app_set_physics_fps(App* app, int fps)
{
    ASSERT_VALID_OBJECT(app);
    app->ms_per_update = 1.0 / fps;
    app->physics_fps = fps;
}

void app_initialize(App* app)
{
    ASSERT_VALID_OBJECT(app);

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_Log("Couldn't start SDL.\n\tError: ", SDL_GetError());
        return;
    }

    app->window = window_new("Pong", (Size){640, 480});
    if (app->window == NULL) {
        SDL_Log("Couldn't create window.\n\tError: ", SDL_GetError());
        return;
    }

    app->renderer = renderer_new(app->window);
    if (app->renderer == NULL) {
        SDL_Log("Couldn't create renderer.\n\tError: ", SDL_GetError());
        return;
    }

    app_ready(app);
}

void app_run(App* app)
{
    ASSERT_VALID_OBJECT(app);

    double a_second = 0.0;
    double last_count = timer_highres_get_ticks_in_seconds();

    SDL_Event event;

    while (app->running) {
        double now = timer_highres_get_ticks_in_seconds();
        app->delta = now - last_count;
        last_count = now;

        a_second += app->delta;

        while (SDL_PollEvent(&event)) {
            app_process_input(app, &event);
        }

        if (a_second >= app->ms_per_update) {
            app_physics_process(app);
            a_second -= app->ms_per_update;
        }

        app_update(app);

        app_render(app);
    }
}

void app_finalize(App* app)
{
    ASSERT_VALID_OBJECT(app);

    debugger_free(app->debugger);
    ball_free(app->ball);

    renderer_free(app->renderer);
    window_free(app->window);

    SDL_Quit();
}

void app_quit(App* app)
{
    ASSERT_VALID_OBJECT(app);
    app->running = false;
}
