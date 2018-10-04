#ifndef EXAMPLES_PONG_BALL_H
#define EXAMPLES_PONG_BALL_H

#include <mng/renderer.h>

#include "app.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Ball {
    Vector2 position;
    Size size;
    Vector2 velocity;
    float speed;
    float min_speed;
    float max_speed;
    Rect bounds;
} Ball;

Ball* ball_new();
void ball_free(Ball* ball);

Rect ball_get_rect(Ball* ball);

void ball_reset(Ball* ball);

void ball_ready(Ball* ball);

void ball_physics_update(Ball* ball, double delta);
void ball_update(Ball* ball, double delta);
void ball_render(Ball* ball, Renderer* renderer);

#ifdef __cplusplus
}
#endif

#endif /* EXAMPLES_PONG_BALL_H */
