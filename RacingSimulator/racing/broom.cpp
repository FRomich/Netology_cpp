#include "broom.h"

my_racing::Broom::Broom()
    : AirVehicles(20, "Метла")
{
}

double my_racing::Broom::getReductionCoefficient(int distance) const
{
    return static_cast<int>(distance / 1000) * 0.01;
}