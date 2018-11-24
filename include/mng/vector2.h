#ifndef MNG_VECTOR2_H
#define MNG_VECTOR2_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Vector2 {
    double x;
    double y;
} Vector2;


Vector2 vector2_add(Vector2 a, Vector2 b);
Vector2 vector2_subtract(Vector2 a, Vector2 b);
Vector2 vector2_multiply(Vector2 a, double scalar);
double vector2_length(Vector2 a);
double vector2_length2(Vector2 a);
Vector2 vector2_normalized(Vector2 a);
double vector2_dot(Vector2 a, Vector2 b);
Vector2 vector2_rotated(Vector2 a, double rad);
double vector2_angle(Vector2 a);

#ifdef __cplusplus
}
#endif

#endif /* MNG_VECTOR2_H */
