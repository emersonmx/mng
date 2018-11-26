#ifndef MNG_GAME_H
#define MNG_GAME_H

#include <mng/event.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*GameInitFunc)(void);
typedef void (*GameQuitFunc)(void);
typedef void (*GameProcessEvent)(Event* event);
typedef void (*GameFixedUpdateFunc)(double delta);
typedef void (*GameUpdateFunc)(double delta);
typedef void (*GameRenderFunc)(void);

typedef struct Game {
    GameInitFunc init;
    GameQuitFunc quit;
    GameProcessEvent process_event;
    GameFixedUpdateFunc fixed_update;
    GameUpdateFunc update;
    GameRenderFunc render;
} Game;


void game_default_init(void);
void game_default_quit(void);
void game_default_process_event(Event* event);
void game_default_fixed_update(double delta);
void game_default_update(double delta);
void game_default_render(void);

Game make_game_with_defaults(Game game);

#ifdef __cplusplus
}
#endif

#endif /* MNG_GAME_H */
