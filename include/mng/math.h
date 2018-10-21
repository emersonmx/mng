#ifndef MNG_MATH_H
#define MNG_MATH_H

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifdef __cplusplus
extern "C" {
#endif

double math_fclamp(double value, double min_value, double max_value);

#ifdef __cplusplus
}
#endif

#endif /* MNG_MATH_H */
