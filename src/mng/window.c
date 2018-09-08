#include <mng/window.h>

#include <mng/macros.h>
#include <mng/window_impl.h>

Window* window_new(const char* title, Size size)
{
    Window* window = malloc(sizeof(Window));
    RETURN_NULL_IF_NULL(window);

    window->handler = SDL_CreateWindow(title,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        size.width, size.height, SDL_WINDOW_SHOWN
    );
    RETURN_NULL_IF_NULL(window->handler);

    return window;
}

void window_destroy(Window* window)
{
    RETURN_IF_NULL(window);
    free(window);
}
