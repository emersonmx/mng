#ifndef MNG_ENGINE_H
#define MNG_ENGINE_H

#include <mng/game.h>

#ifdef __cplusplus
extern "C" {
#endif

void engine_run(Game game);
void engine_quit(void);

#ifdef __cplusplus
}
#endif

#endif /* MNG_ENGINE_H */
