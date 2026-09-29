#include "eagle.h"

my_racing::Eagle::Eagle()
    : AirVehicles(8, "Орёл")
{
}

double my_racing::Eagle::getReductionCoefficient(int distance) const
{
    return 0.06;
}