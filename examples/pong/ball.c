#include "ball.h"

#include <time.h>
#include <math.h>
#include <stdlib.h>

#include <mng/macros.h>

Ball* ball_new()
{
    Ball* ball = malloc(sizeof(Ball));
    RETURN_VALUE_IF_NULL(ball, NULL);

    ball->size = (Size){6, 6};
    ball->speed = 100;
    ball->min_speed = 100;
    ball->max_speed = 1000;

    return ball;
}

void ball_free(Ball* ball)
{
    RETURN_IF_NULL(ball);
    free(ball);
}

Rect ball_get_rect(Ball* ball)
{
    ASSERT_VALID_OBJECT(ball);

    Point point = {
        ball->position.x - ball->size.width / 2.0f,
        ball->position.y - ball->size.height / 2.0f,
    };

    return (Rect){
        point.x, point.y,
        ball->size.width, ball->size.height
    };
}

void ball_reset(Ball* ball)
{
    ASSERT_VALID_OBJECT(ball);
    srand(time(NULL));
    float high = -M_PI/4;
    float low = M_PI/4;
    float range = high - low;
    float direction = (rand() / (float) RAND_MAX) * range + low;
    ball->velocity = vector2_rotated((Vector2){1, 0}, direction);
    ball->velocity.x *= rand() % 2 == 0 ? -1 : 1;
}

void ball_ready(Ball* ball)
{
    ASSERT_VALID_OBJECT(ball);
    ball_reset(ball);
}

void ball_physics_update(Ball* ball, double delta)
{
    ASSERT_VALID_OBJECT(ball);
    Vector2 nvel = vector2_normalized(ball->velocity);
    Vector2 position = vector2_multiply(nvel, ball->speed * delta);
    ball->position = vector2_add(ball->position, position);
}

void ball_update(Ball* ball, double delta)
{
    ASSERT_VALID_OBJECT(ball);
}

void ball_render(Ball* ball, Renderer* renderer)
{
    ASSERT_VALID_OBJECT(ball);

    renderer_set_draw_color(renderer, (Color){255, 255, 255, 255});
    renderer_fill_rect(renderer, ball_get_rect(ball));
}
