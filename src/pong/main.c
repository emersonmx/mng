#include <stdbool.h>
#include <stdio.h>

#include <SDL.h>

#include <mng/window.h>
#include <mng/renderer.h>

bool running = true;
SDL_Event event;
Window* window = NULL;
Renderer* renderer = NULL;

void Initialize()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_Log("Couldn't start SDL.\n\tError: ", SDL_GetError());
        return;
    }

    window = window_new("Hello world", (Size){800, 600});
    if (window == NULL) {
        SDL_Log("Couldn't create window.\n\tError: ", SDL_GetError());
        return;
    }

    renderer = renderer_new(window);
    if (renderer == NULL) {
        SDL_Log("Couldn't create renderer.\n\tError: ", SDL_GetError());
        return;
    }
}

void Finalize()
{
    renderer_destroy(renderer);
    window_destroy(window);

    SDL_Quit();
}

int main()
{
    atexit(Finalize);
    Initialize();

    float x = 0;
    float y = 0;
    float vx = 1;
    float vy = 1;
    float speed = 5;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        float delta = 1/60.f;
        if (x < 0 || x > 800) {
            vx = -vx;
        }
        if (y < 0 || y > 600) {
            vy = -vy;
        }
        x += vx * speed * delta;
        y += vy * speed * delta;

        renderer_set_draw_color(renderer, (Color){0, 0, 0, 255});
        renderer_clear(renderer);

        renderer_set_draw_color(renderer, (Color){255, 0, 0, 255});
        renderer_fill_rect(renderer, (Rect){x, y, 10, 10});

        renderer_present(renderer);
    }

    return 0;
}
