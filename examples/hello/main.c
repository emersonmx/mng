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

    window = window_new();
    if (window == NULL) {
        SDL_Log("Couldn't create window.\n\tError: %s", SDL_GetError());
        return;
    }

    window_set_title(window, "Hello world");

    printf("Title \"%s\"\n", window_get_title(window));
    Size size = window_get_size(window);
    printf("Size %dx%d\n", size.width, size.height);
    printf("Resizable? %s\n", window_is_resizable(window) ? "yes": "no");
    printf("Fullscreen? %s\n", window_is_fullscreen(window) ? "yes": "no");

    window_create(window);

    renderer = renderer_new(window);
    if (renderer == NULL) {
        SDL_Log("Couldn't create renderer.\n\tError: %s", SDL_GetError());
        return;
    }

    renderer_create(renderer);

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
    double speed = 200;
    double a_second = 0;
    double last_count = timer_highres_get_ticks_in_seconds();

    const double MS_PER_UPDATE = 1/60.0;
    Size s = texture_get_size(texture);
    sprite->region = (Rect){200, 200, s.width-200, s.height-200};
    sprite->scale = (Vector2){-0.6, 0.6};
    sprite->position = (Point2){s.width / 2.0, s.height / 2.0};
    sprite->origin = (Point2){s.width / 2.0, s.height / 2.0};
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
        renderer_set_draw_color(renderer, (Color){1.0f, 0.0f, 0.0f, 1.0f});
        renderer_fill_rect(renderer, (Rect){p.x, p.y, 10, 10});

        renderer_present(renderer);
    }

    return 0;
}
