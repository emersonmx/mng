#include <mng/window.h>

#include <mng/macros.h>
#include <mng/window_impl.h>

Window* window_new(const char* title, Size size)
{
    Window* window = malloc(sizeof(Window));
    RETURN_VALUE_IF_NULL(window, NULL);

    window->handler = SDL_CreateWindow(title,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        size.width, size.height, SDL_WINDOW_SHOWN
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

Size window_get_size(Window* window)
{
    ASSERT_VALID_OBJECT(window);

    Size size;
    SDL_GetWindowSize(window->handler, &size.width, &size.height);
    return size;
}
