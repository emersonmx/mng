#include <mng/vector2.h>

#include <math.h>

Vector2 vector2_add(Vector2 a, Vector2 b)
{
    return (Vector2){a.x + b.x, a.y + b.y};
}

Vector2 vector2_subtract(Vector2 a, Vector2 b)
{
    return (Vector2){a.x - b.x, a.y - b.y};
}

Vector2 vector2_multiply(Vector2 a, double scalar)
{
    return (Vector2){a.x * scalar, a.y * scalar};
}

double vector2_length(Vector2 a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}

double vector2_length_squared(Vector2 a)
{
    return a.x * a.x + a.y * a.y;
}

Vector2 vector2_normalized(Vector2 a)
{
    return vector2_multiply(a, 1.0 / vector2_length(a));
}

double vector2_dot(Vector2 a, Vector2 b)
{
    return a.x * b.x + a.y * b.y;
}

Vector2 vector2_rotated(Vector2 a, double rad)
{
    double angle = vector2_angle(a) + rad;
    Vector2 v = { cos(angle), sin(angle) };
    return vector2_multiply(v, vector2_length(v));
}

double vector2_angle(Vector2 a)
{
    return atan2(a.y, a.x);
}
