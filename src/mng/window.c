#include <mng/window.h>

#include <mng/macros.h>
#include <mng/window_impl.h>

Window* window_new(void)
{
    Window* window = malloc(sizeof(Window));
    RETURN_VALUE_IF_NULL(window, NULL);

    window->handler = SDL_CreateWindow("Game Window",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600, SDL_WINDOW_SHOWN
    );
    RETURN_VALUE_IF_NULL(window->handler, NULL);

    return window;
}

void window_free(Window* window)
{
    RETURN_IF_NULL(window);
    SDL_DestroyWindow(window->handler);
    free(window);
}

const char* window_get_title(Window* window)
{
    ASSERT_VALID_OBJECT(window);
    return SDL_GetWindowTitle(window->handler);
}

void window_set_title(Window* window, const char* title)
{
    ASSERT_VALID_OBJECT(window);
    SDL_SetWindowTitle(window->handler, title);
}

Point2 window_get_position(Window* window)
{
    ASSERT_VALID_OBJECT(window);
    Point2 position;
    SDL_GetWindowPosition(window->handler, &position.x, &position.y);
    return position;
}

void window_set_position(Window* window, const Point2 position)
{
    ASSERT_VALID_OBJECT(window);
    SDL_SetWindowPosition(window->handler, position.x, position.y);
}

void window_center_position(Window* window)
{
    window_set_position(window, (Point2){
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED
    });
}

Size window_get_size(Window* window)
{
    ASSERT_VALID_OBJECT(window);

    Size size;
    SDL_GetWindowSize(window->handler, &size.width, &size.height);
    return size;
}

void window_set_size(Window* window, const Size size)
{
    ASSERT_VALID_OBJECT(window);
    SDL_SetWindowSize(window->handler, size.width, size.height);
}

bool window_is_resizable(Window* window)
{
    ASSERT_VALID_OBJECT(window);
    Uint32 flags = SDL_GetWindowFlags(window->handler);
    return (SDL_WINDOW_RESIZABLE & flags) == SDL_WINDOW_RESIZABLE;
}

void window_set_resizable(Window* window, bool resizable)
{
    ASSERT_VALID_OBJECT(window);
    SDL_SetWindowResizable(window->handler, resizable);
}

bool window_is_fullscreen(Window* window)
{
    ASSERT_VALID_OBJECT(window);
    Uint32 flags = SDL_GetWindowFlags(window->handler);
    return (SDL_WINDOW_FULLSCREEN & flags) == SDL_WINDOW_FULLSCREEN;
}

void window_set_fullscreen(Window* window, bool fullscreen)
{
    ASSERT_VALID_OBJECT(window);

    Uint32 flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    SDL_SetWindowFullscreen(window->handler, flags);
}
