#ifndef MNG_GAME_H
#define MNG_GAME_H

#include <mng/input_event.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*GameInitFunc)(void);
typedef void (*GameQuitFunc)(void);
typedef void (*GameInputFunc)(const InputEvent* input);
typedef void (*GameFixedUpdateFunc)(double delta);
typedef void (*GameUpdateFunc)(double delta);
typedef void (*GameRenderFunc)(void);

typedef struct Game {
    GameInitFunc init;
    GameQuitFunc quit;
    GameInputFunc input;
    GameFixedUpdateFunc fixed_update;
    GameUpdateFunc update;
    GameRenderFunc render;
} Game;


void game_default_init(void);
void game_default_quit(void);
void game_default_input(const InputEvent* input);
void game_default_fixed_update(double delta);
void game_default_update(double delta);
void game_default_render(void);

#ifdef __cplusplus
}
#endif

#endif /* MNG_GAME_H */
