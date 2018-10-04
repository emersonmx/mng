#include "ball.h"

#include <stdlib.h>

#include <mng/macros.h>

Ball* ball_new()
{
    Ball* ball = malloc(sizeof(Ball));
    RETURN_VALUE_IF_NULL(ball, NULL);

    ball->position = (Vector2){320, 240};
    ball->size = (Size){6, 6};

    return ball;
}

void ball_free(Ball* ball)
{
    RETURN_IF_NULL(ball);
    free(ball);
}

void ball_ready(Ball* ball)
{
    ASSERT_VALID_OBJECT(ball);
}

void ball_physics_update(Ball* ball)
{
    ASSERT_VALID_OBJECT(ball);
}

void ball_update(Ball* ball)
{
    ASSERT_VALID_OBJECT(ball);
}

void ball_render(Ball* ball, Renderer* renderer)
{
    ASSERT_VALID_OBJECT(ball);

    Point point = {
        ball->position.x - ball->size.width / 2.0f,
        ball->position.y - ball->size.height / 2.0f,
    };

    renderer_set_draw_color(renderer, (Color){255, 255, 255, 255});
    renderer_fill_rect(renderer, (Rect){
        point.x, point.y,
        ball->size.width, ball->size.height
    });
}
