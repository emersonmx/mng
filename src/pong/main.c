#include <stdbool.h>
#include <stdio.h>

#include <SDL.h>

#include <mng/vector2.h>
#include <mng/window.h>
#include <mng/renderer.h>
#include <mng/loaders.h>

bool running = true;
SDL_Event event;
Window* window = NULL;
Renderer* renderer = NULL;
Texture* texture = NULL;

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

    texture = load_texture(renderer, "hello.png");
}

void Finalize()
{
    texture_free(texture);

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
    float speed = 200;
    float a_second = 0;
    Uint64 now = SDL_GetPerformanceCounter();
    Uint64 last_count = SDL_GetPerformanceCounter();
    float delta = 1/60.f;
    Transform transform = transform_reseted();
    Size s = texture_size(texture);
    transform.scale = (Vector2){-0.6, -0.6};
    transform.position = (Vector2){ s.width / 2.0f, s.height / 2.0f };
    transform.origin = (Vector2){ s.width / 2.0f, s.height / 2.0f };
    while (running) {
        // start_loop
        now = SDL_GetPerformanceCounter();

        double deltaTime = (double)((now - last_count)*1000 / (double)SDL_GetPerformanceFrequency());
        last_count = SDL_GetPerformanceCounter();
        a_second += (deltaTime * 0.001);

        // process input
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // fixed update
        if (a_second >= delta) {
            p = vector2_add(p, vector2_multiply(vector2_normalized(v), speed * delta));

            a_second -= delta;
        }

        // update
        if (p.x < 0) {
            v.x = 1;
        }
        if (p.x + 10 > 800) {
            v.x = -1;
        }
        if (p.y < 0) {
            v.y = 1;
        }
        if (p.y + 10 > 600) {
            v.y = -1;
        }

        transform.rotation += delta * 5;

        // render
        renderer_clear(renderer);

        renderer_draw_texture(renderer, texture, transform);
        renderer_set_draw_color(renderer, (Color){255, 0, 0, 255});
        renderer_fill_rect(renderer, (Rect){p.x, p.y, 10, 10});

        renderer_present(renderer);
    }

    return 0;
}
