#include "ground_vehicles.h"
#include <cmath>

double my_racing::GroundVehicles::getTimeRacing(int distance) const
{
	double time = static_cast<double>(distance) / Vehicle::getSpeed() * 60.0;

	int countRest = static_cast<int>(time / timeToRest);

	if (std::fmod(time, timeToRest) == 0.0)
		--countRest;

    if (countRest == 0)
        return time;

    if (countRest == 1)
        return time + firstRestDuration;

    if (countRest == 2)
        return time
        + firstRestDuration
        + secondRestDuration;

    return time
        + firstRestDuration
        + secondRestDuration
        + subsequentRestDuration * (countRest - 2);
}
