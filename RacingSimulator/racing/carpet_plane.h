#pragma once
#include "air_vehicles.h"

namespace my_racing {
	class RACINGLIBRARY CarpetPlane : public AirVehicles
	{

	protected:
		double getReductionCoefficient(int distance) const override;

	public:
		CarpetPlane();
	};
}
