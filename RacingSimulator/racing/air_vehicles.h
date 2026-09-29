#pragma once
#include "vehicle.h"

namespace my_racing {
	class RACINGLIBRARY AirVehicles : public Vehicle
	{
	protected:
		AirVehicles(int speed,
			const std::string& name)
			: Vehicle(TypeVehicle::air, name, speed)
		{
		}

		virtual double getReductionCoefficient(int distance) const = 0;

	public:
		double getTimeRacing(int distance) const override;
	}; 
}


