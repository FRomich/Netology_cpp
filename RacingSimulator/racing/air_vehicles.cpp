#include "air_vehicles.h"

double my_racing::AirVehicles::getTimeRacing(int distance) const
{
    double coefficient = getReductionCoefficient(distance);

    double reducedDistance =
        distance * (1.0 - coefficient);

    return reducedDistance / getSpeed() * 60.0;
}