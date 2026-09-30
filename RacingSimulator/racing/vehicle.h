#pragma once
#include <string>

#include "racing_export.h"

namespace my_racing
{
	enum class TypeVehicle
	{
		ground,
		air
	};

	class RACINGLIBRARY Vehicle
	{
	private:
		TypeVehicle type;
		std::string name;
		int speed;

	public:
		Vehicle(TypeVehicle type, const std::string& setName, int setSpeed);
		virtual ~Vehicle() = default;

		TypeVehicle getType() const;
		std::string getTypeName() const;

		int getSpeed() const;
		std::string getName() const;
		virtual double getTimeRacing(int distance) const = 0;
	};
}
