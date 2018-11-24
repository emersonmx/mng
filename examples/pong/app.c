#include "app.h"

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include <SDL.h>

#include <mng/macros.h>
#include <mng/timer.h>

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
    srand(time(NULL));
    Size window_size = window_get_size(app->window);

    app->ball = ball_new();
    app->ball->bounds = (Rect){
        0, 0,
        window_size.width, window_size.height
    };
    app->ball->position = vector2_multiply(size_to_vector2(window_size), 0.5);
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
    double delta = app_get_physics_process_delta_time(app);
    ball_physics_update(app->ball, delta);
}

void app_update(App* app)
{
    double delta = app->delta;
    ball_update(app->ball, delta);
}

void app_render(App* app)
{
    renderer_clear(app->renderer);
    ball_render(app->ball, app->renderer);

    debugger_render(app->debugger, app->renderer);
    renderer_present(app->renderer);
}

void _app_initialize(App* app)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_Log("Couldn't start SDL.\n\tError: %s", SDL_GetError());
        return;
    }

    app->window = window_new();
    if (app->window == NULL) {
        SDL_Log("Couldn't create window.\n\tError: %s", SDL_GetError());
        return;
    }

    window_set_title(app->window, "Pong");
    printf("Title \"%s\"\n", window_get_title(app->window));
    window_set_size(app->window, (Size){640, 480});
    Size size = window_get_size(app->window);
    printf("Size %dx%d\n", size.width, size.height);

    app->renderer = renderer_new(app->window);
    if (app->renderer == NULL) {
        SDL_Log("Couldn't create renderer.\n\tError: %s", SDL_GetError());
        return;
    }

    app_ready(app);
}

void _app_finalize(App* app)
{
    debugger_free(app->debugger);
    ball_free(app->ball);

    renderer_free(app->renderer);
    window_free(app->window);

    SDL_Quit();
}

App* app_new(void)
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

Window* app_get_window(App* app)
{
    ASSERT_VALID_OBJECT(app);
    return app->window;
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

double app_get_physics_process_delta_time(App* app)
{
    ASSERT_VALID_OBJECT(app);
    return app->ms_per_update;
}

void app_run(App* app)
{
    ASSERT_VALID_OBJECT(app);

    _app_initialize(app);

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

    _app_finalize(app);
}

void app_quit(App* app)
{
    ASSERT_VALID_OBJECT(app);
    app->running = false;
}
