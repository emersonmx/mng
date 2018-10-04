#include "debugger.h"

#include <stdlib.h>

#include <mng/macros.h>

struct Debugger {
    App* app;
};

Debugger* debugger_new(App* app)
{
    ASSERT_VALID_OBJECT(app);

    Debugger* debugger = malloc(sizeof(Debugger));
    RETURN_VALUE_IF_NULL(debugger, NULL);

    debugger->app = app;

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
}
