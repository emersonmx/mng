#include <mng/window.h>

#include <mng/macros.h>
#include <mng/window_impl.h>

Window* window_new(void)
{
    Window* window = malloc(sizeof(Window));
    RETURN_VALUE_IF_NULL(window, NULL);

    window->handler = NULL;
    window->title = "Game Window";
    window->position = (Point2){
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED
    };
    window->size = (Size){800, 600};
    window->resizable = false;
    window->fullscreen = false;

    return window;
}

void window_free(Window* window)
{
    RETURN_IF_NULL(window);
    window_destroy(window);
    free(window);
}

bool window_was_created(Window* window)
{
    ASSERT_VALID_OBJECT(window);
    return window->handler != NULL;
}

const char* window_get_title(Window* window)
{
    ASSERT_VALID_OBJECT(window);
    return window->title;
}

void window_set_title(Window* window, const char* title)
{
    ASSERT_VALID_OBJECT(window);
    window->title = title;
    RETURN_IF_NULL(window->handler);

    SDL_SetWindowTitle(window->handler, title);
}

Point2 window_get_position(Window* window)
{
    ASSERT_VALID_OBJECT(window);
    return window->position;
}

void window_set_position(Window* window, Point2 position)
{
    ASSERT_VALID_OBJECT(window);
    window->position = position;
    RETURN_IF_NULL(window->handler);

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
    return window->size;
}

void window_set_size(Window* window, Size size)
{
    ASSERT_VALID_OBJECT(window);
    window->size = size;
    RETURN_IF_NULL(window->handler);

    SDL_SetWindowSize(window->handler, size.width, size.height);
}

bool window_is_resizable(Window* window)
{
    ASSERT_VALID_OBJECT(window);
    return window->resizable;
}

void window_set_resizable(Window* window, bool resizable)
{
    ASSERT_VALID_OBJECT(window);
    window->resizable = resizable;
    RETURN_IF_NULL(window->handler);

    SDL_SetWindowResizable(window->handler, resizable);
}

bool window_is_fullscreen(Window* window)
{
    ASSERT_VALID_OBJECT(window);
    return window->fullscreen;
}

void window_set_fullscreen(Window* window, bool fullscreen)
{
    ASSERT_VALID_OBJECT(window);
    window->fullscreen = fullscreen;
    RETURN_IF_NULL(window->handler);

    Uint32 flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    SDL_SetWindowFullscreen(window->handler, flags);
}

void window_create(Window* window)
{
    ASSERT_VALID_OBJECT(window);

    window_destroy(window);

    window->handler = SDL_CreateWindow(window->title,
        window->position.x, window->position.y,
        window->size.width, window->size.height,
        SDL_WINDOW_SHOWN
    );
}

void window_destroy(Window* window)
{
    ASSERT_VALID_OBJECT(window);
    SDL_DestroyWindow(window->handler);
    window->handler = NULL;
}
