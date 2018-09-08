#include <mng/vector2.h>

#include <stdio.h>
#include <math.h>

Vector2 vector2_add(Vector2 a, Vector2 b)
{
    printf("%f, %f\n", b.x, b.y);
    return (Vector2){a.x + b.x, a.y + b.y};
}

Vector2 vector2_subtract(Vector2 a, Vector2 b)
{
    return (Vector2){a.x - b.x, a.y - b.y};
}

Vector2 vector2_multiply(Vector2 a, float scalar)
{
    return (Vector2){a.x * scalar, a.y * scalar};
}

float vector2_length(Vector2 a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}

float vector2_length_squared(Vector2 a)
{
    return a.x * a.x + a.y * a.y;
}

Vector2 vector2_normalized(Vector2 a)
{
    return vector2_multiply(a, 1.0f / vector2_length(a));
}

float vector2_dot(Vector2 a, Vector2 b)
{
    return a.x * b.x + a.y * b.y;
}
