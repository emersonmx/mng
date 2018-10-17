#include <stdbool.h>
#include <stdio.h>

#include <SDL.h>

#include <mng/timer.h>
#include <mng/vector2.h>
#include <mng/window.h>
#include <mng/renderer.h>
#include <mng/resources.h>

bool running = true;
SDL_Event event;
Window* window = NULL;
Renderer* renderer = NULL;
Texture* texture = NULL;
Sprite* sprite = NULL;

void Initialize(void)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_Log("Couldn't start SDL.\n\tError: %s", SDL_GetError());
        return;
    }

    window = window_new("Hello world", (Size){800, 600});
    if (window == NULL) {
        SDL_Log("Couldn't create window.\n\tError: %s", SDL_GetError());
        return;
    }

    renderer = renderer_new(window);
    if (renderer == NULL) {
        SDL_Log("Couldn't create renderer.\n\tError: %s", SDL_GetError());
        return;
    }

    texture = load_texture(renderer, "assets/hello.png");
    sprite = sprite_new();
    sprite->texture = texture;
}

void Finalize(void)
{
    sprite_free(sprite);
    texture_free(texture);

    renderer_free(renderer);
    window_free(window);

    SDL_Quit();
}

int main(int argc, char* argv[])
{
    atexit(Finalize);
    Initialize();

    Vector2 p = {0, 0};
    Vector2 v = {1, 1};
    float speed = 200;
    float a_second = 0;
    double last_count = timer_highres_get_ticks_in_seconds();

    const double MS_PER_UPDATE = 1/60.0;
    Size s = texture_get_size(texture);
    sprite->region = (Rect){200, 200, s.width-200, s.height-200};
    sprite->scale = (Vector2){-0.6, 0.6};
    sprite->position = (Point){s.width / 2.0f, s.height / 2.0f};
    sprite->origin = (Point){s.width / 2.0f, s.height / 2.0f};
    while (running) {
        // start_loop
        double now = timer_highres_get_ticks_in_seconds();
        double delta = now - last_count;
        last_count = now;

        a_second += delta;

        // process input
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // fixed update
        if (a_second >= MS_PER_UPDATE) {
            p = vector2_add(p, vector2_multiply(vector2_normalized(v), speed * MS_PER_UPDATE));

            sprite->rotation += MS_PER_UPDATE * 50;

            a_second -= MS_PER_UPDATE;
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

        // render
        renderer_clear(renderer);

        renderer_draw_sprite(renderer, sprite);
        renderer_set_draw_color(renderer, (Color){255, 0, 0, 255});
        renderer_fill_rect(renderer, (Rect){p.x, p.y, 10, 10});

        renderer_present(renderer);
    }

    return 0;
}
