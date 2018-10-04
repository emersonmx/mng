#include "utils.h"

#include <math.h>

float clamp(float value, float min_value, float max_value)
{
    return fmin(fmax(value, min_value), max_value);
}
