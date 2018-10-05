#include <mng/random.h>

#include <stdlib.h>

double rand_range(double low, double high)
{
    double random = rand() / (double) RAND_MAX;
    return random * (high - low) + low;
}
