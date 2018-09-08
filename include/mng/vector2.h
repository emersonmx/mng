#ifndef MNG_VECTOR2_H
#define MNG_VECTOR2_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Vector2 {
    float x;
    float y;
} Vector2;

Vector2 vector2_add(Vector2 a, Vector2 b);
Vector2 vector2_subtract(Vector2 a, Vector2 b);
Vector2 vector2_multiply(Vector2 a, float scalar);
float vector2_length(Vector2 a);
float vector2_length_squared(Vector2 a);
Vector2 vector2_normalized(Vector2 a);
float vector2_dot(Vector2 a, Vector2 b);

#ifdef __cplusplus
}
#endif

#endif /* MNG_VECTOR2_H */
