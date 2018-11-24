#include <mng/game.h>

void game_default_init(void)
{
}

void game_default_quit(void)
{
}

void game_default_input(const InputEvent* input)
{
}

void game_default_fixed_update(double delta)
{
}

void game_default_update(double delta)
{
}

void game_default_render(void)
{
}

Game make_game_with_defaults(Game game)
{
    return (Game){
        .init = game.init ? game.init : &game_default_init,
        .quit = game.quit ? game.quit : &game_default_quit,
        .input = game.input ? game.input : &game_default_input,
        .fixed_update = game.fixed_update
            ? game.fixed_update : &game_default_fixed_update,
        .update = game.update ? game.update : &game_default_update,
        .render = game.render ? game.render : &game_default_render
    };
}
