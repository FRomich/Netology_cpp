#pragma once
#include "vehicle.h"

namespace my_racing {
	class RACINGLIBRARY GroundVehicles : public Vehicle
	{
	private:
		int timeToRest;
		double firstRestDuration;
		double secondRestDuration;
		double subsequentRestDuration;

    protected:
        GroundVehicles(
            int speed,
            const std::string& name,
            int timeToRestValue,
            double firstRestDurationValue,
            double secondRestDurationValue,
            double subsequentRestDurationValue
        )
            : Vehicle(TypeVehicle::ground, name, speed),
            timeToRest(timeToRestValue),
            firstRestDuration(firstRestDurationValue),
            secondRestDuration(secondRestDurationValue),
            subsequentRestDuration(subsequentRestDurationValue)
        {
        }

	public:
		double getTimeRacing(int distance) const override;

	};
}
