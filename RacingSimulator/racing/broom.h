#pragma once
#include "air_vehicles.h"

namespace my_racing {
	class RACINGLIBRARY Broom : public AirVehicles
	{

	protected:
		double getReductionCoefficient(int distance) const override;

	public:
		Broom();
	};
}