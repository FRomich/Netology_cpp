#include "eagle.h"

my_racing::Eagle::Eagle()
    : AirVehicles(8, "Îð¸ë")
{
}

double my_racing::Eagle::getReductionCoefficient(int distance) const
{
    return 0.06;
}