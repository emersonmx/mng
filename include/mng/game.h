#ifndef MNG_GAME_H
#define MNG_GAME_H

#include <mng/input_event.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*InitFunc)(void);
typedef void (*QuitFunc)(void);
typedef void (*InputFunc)(InputEvent* input);
typedef void (*FixedUpdateFunc)(double delta);
typedef void (*UpdateFunc)(double delta);
typedef void (*RenderFunc)(void);

typedef struct Game {
    InitFunc init;
    QuitFunc quit;
    InputFunc input;
    FixedUpdateFunc fixed_update;
    UpdateFunc update;
    RenderFunc render;
} Game;


void default_init_func(void);
void default_quit_func(void);
void default_input_func(InputEvent* input);
void default_fixed_update_func(double delta);
void default_update_func(double delta);
void default_render_func(void);

#ifdef __cplusplus
}
#endif

#endif /* MNG_GAME_H */
