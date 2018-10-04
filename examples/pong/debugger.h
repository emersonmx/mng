#ifndef EXAMPLES_PONG_DEBUGGER_H
#define EXAMPLES_PONG_DEBUGGER_H

#include <mng/renderer.h>

#include "app.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Debugger Debugger;

Debugger* debugger_new(App* app);
void debugger_free(Debugger* debugger);

void debugger_ready(Debugger* debugger);
void debugger_render(Debugger* debugger, Renderer* renderer);

#ifdef __cplusplus
}
#endif

#endif /* EXAMPLES_PONG_DEBUGGER_H */
