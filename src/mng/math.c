#include <mng/math.h>

#include <stdlib.h>

double math_fclamp(double value, double min_value, double max_value)
{
    return fmin(fmax(value, min_value), max_value);
}
