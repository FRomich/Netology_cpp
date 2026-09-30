#include "race.h"

#include <algorithm>
#include <iomanip>
#include <sstream>

namespace my_racing
{
    Race::Race(RaceType setType, int setDistance)
        : type(setType), distance(setDistance)
    {
    }

    bool Race::canRegister(const Vehicle& vehicle) const
    {
        switch (type)
        {
        case RaceType::Ground:
            return vehicle.getType() == TypeVehicle::ground;

        case RaceType::Air:
            return vehicle.getType() == TypeVehicle::air;

        case RaceType::Mixed:
            return (vehicle.getType() == TypeVehicle::air || 
                vehicle.getType() == TypeVehicle::ground);
        }

        return false;
    }

    bool Race::isRegistered(const Vehicle& vehicle) const
    {
        for (const auto& registeredVehicle : vehicles)
        {
            if (registeredVehicle->getName() == vehicle.getName())
            {
                return true;
            }
        }

        return false;
    }

    bool Race::registerVehicle(std::unique_ptr<Vehicle> vehicle)
    {
        if (!vehicle)
            return false;

        if (!canRegister(*vehicle))
            return false;

        vehicles.push_back(std::move(vehicle));
        return true;
    }

    std::vector<std::string> Race::getVehicleNames() const
    {
        std::vector<std::string> names;

        for (const auto& vehicle : vehicles)
        {
            names.push_back(vehicle->getName());
        }

        return names;
    }

    RaceType Race::getType() const
    {
        return type;
    }

    std::string Race::getTypeName() const
    {
        switch (type)
        {
        case RaceType::Ground:
            return "Гонка для наземного транспорта";

        case RaceType::Air:
            return "Гонка для воздушного транспорта";

        case RaceType::Mixed:
            return "Гонка для наземного и воздушного транспорта";

        default:
            return "Неизвестный тип гонки";
        }
    }

    int Race::getDistanse() const
    {
        return distance;
    };

    std::size_t Race::getCountVehicles() const
    {
        return static_cast<int>(vehicles.size());
    }

    void Race::setStatus(std::string setStatus)
    {
        status = setStatus;
    }

    std::string Race::getStatus() const
    {
        return status;
    }

    std::string Race::getResult() const
    {
        return raceResults;
    }

    void Race::start()
    {
        std::vector<std::pair<std::string, double>> results;

	    for (const auto& registeredVehicle : vehicles)
	    {
            results.emplace_back(
                registeredVehicle->getName(),
                registeredVehicle->getTimeRacing(distance)
            );
	    }

        std::sort(
            results.begin(),
            results.end(),
            [](const auto& a, const auto& b)
            {
                return a.second < b.second;
            }
        );

        std::ostringstream oss;

        for (size_t i = 0; i < results.size(); ++i)
        {
            oss << i + 1 << ". "
                << results[i].first
                << " Время: "
                << std::fixed << std::setprecision(2)
                << results[i].second
                << "\n";
        }

        raceResults = oss.str();

    }



}
