#ifndef EXAMPLES_PONG_BALL_H
#define EXAMPLES_PONG_BALL_H

#include <mng/renderer.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Ball {
    Vector2 position;
    Size size;
} Ball;

Ball* ball_new();
void ball_free(Ball* ball);

void ball_ready(Ball* ball);

void ball_physics_update(Ball* ball);
void ball_update(Ball* ball);
void ball_render(Ball* ball, Renderer* renderer);

#ifdef __cplusplus
}
#endif

#endif /* EXAMPLES_PONG_BALL_H */
