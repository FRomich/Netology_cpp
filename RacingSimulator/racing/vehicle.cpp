#include "vehicle.h"

namespace my_racing
{
    Vehicle::Vehicle(TypeVehicle setType, const std::string& setName, int setSpeed)
        : type(setType), name(setName), speed(setSpeed)
    {
    }

    std::string Vehicle::getTypeName() const
    {
        switch (type)
        {
        case TypeVehicle::ground:
            return "Наземный";

        case TypeVehicle::air:
            return "Воздушный";

        default:
            return "Неизвестный";
        }
    }

    TypeVehicle Vehicle::getType() const
    {
        return type;
    }

    int Vehicle::getSpeed() const
    {
        return speed;
    }

    std::string Vehicle::getName() const
    {
        return name;
    }

}