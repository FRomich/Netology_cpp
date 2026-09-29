#include "carpet_plane.h"

my_racing::CarpetPlane::CarpetPlane()
    : AirVehicles(10, "Ковер-самолет")
{
}

double my_racing::CarpetPlane::getReductionCoefficient(int distance) const
{
    if (distance < 1000)
        return 0.0;

    if (distance < 5000)
        return 0.03;

    if (distance < 10000)
        return 0.10;

    return 0.05;
}