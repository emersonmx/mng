#include <stdio.h>

#include <mng/timer.h>
#include <mng/vector2.h>
#include <mng/window.h>
#include <mng/renderer.h>
#include <mng/resources.h>
#include <mng/game.h>
#include <mng/engine.h>

void init(void)
{
    printf("Init\n");
}

void quit(void)
{
    printf("Quit\n");
}

void update(double delta)
{
    printf("Update %f\n", delta);
}

void fixed_update(double delta)
{
    printf("Fixed Update %f\n", delta);
}

int main(int argc, char* argv[]) {
    EngineSettings settings = {
        .window = {
            .title = "Hello world - Engine",
            .centered = true,
            .size = (Size){800, 600},
            .resizable = false,
            .fullscreen = false
        },
        .renderer = {
            .vsync = true
        }
    };

    engine_set_settings(settings);
    engine_run(make_game_with_defaults((Game){
        .init = &init,
        .quit = &quit,
        .update = &update,
        .fixed_update = &fixed_update
    }));

    return 0;
}
