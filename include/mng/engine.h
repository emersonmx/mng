#ifndef MNG_ENGINE_H
#define MNG_ENGINE_H

#include <mng/game.h>

#ifdef __cplusplus
extern "C" {
#endif

void mng_load_settings_from_file(const char* filename);
void mng_run(Game game);
void mng_quit(void);

#ifdef __cplusplus
}
#endif

#endif /* MNG_ENGINE_H */
