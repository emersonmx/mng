#include <stdbool.h>
#include <stdio.h>

#include <SDL.h>

#include <mng/vector2.h>
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
    renderer_free(renderer);
    window_free(window);

    SDL_Quit();
}

int main()
{
    atexit(Finalize);
    Initialize();

    Vector2 p = {0, 0};
    Vector2 v = {1, 1};
    float speed = 5;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        float delta = 1/60.f;
        if (p.x < 0 || p.x > 800) {
            v.x = -v.x;
        }
        if (p.y < 0 || p.y > 600) {
            v.y = -v.y;
        }

        p = vector2_add(p, vector2_multiply(vector2_normalized(v), speed * delta));

        renderer_clear(renderer);

        renderer_set_draw_color(renderer, (Color){255, 0, 0, 255});
        renderer_fill_rect(renderer, (Rect){p.x, p.y, 10, 10});

        renderer_present(renderer);
    }

    return 0;
}
