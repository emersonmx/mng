#include "debugger.h"

#include <stdlib.h>

#include <mng/macros.h>

struct Debugger {
    App* app;
    Color guides_color;
};

Debugger* debugger_new(App* app)
{
    ASSERT_VALID_OBJECT(app);

    Debugger* debugger = malloc(sizeof(Debugger));
    RETURN_VALUE_IF_NULL(debugger, NULL);

    debugger->app = app;
    debugger->guides_color = (Color){255, 92, 92, 64};

    return debugger;
}

void debugger_free(Debugger* debugger)
{
    RETURN_IF_NULL(debugger);
    free(debugger);
}

void debugger_ready(Debugger* debugger)
{
    ASSERT_VALID_OBJECT(debugger);
}

void debugger_render(Debugger* debugger, Renderer* renderer)
{
    ASSERT_VALID_OBJECT(debugger);
    renderer_set_draw_color(renderer, debugger->guides_color);

    Size window_size = window_get_size(app_get_window(debugger->app));
    int hcenter = window_size.width / 2.0;
    int vcenter = window_size.height / 2.0;
    Line vline = {
        {hcenter, 0}, {hcenter, window_size.height}
    };
    Line hline = {
        {0, vcenter}, {window_size.width, vcenter}
    };

    renderer_draw_line(renderer, vline);
    renderer_draw_line(renderer, hline);
}
