#pragma once

#include <memory>
#include <vector>
#include <string>

#include "vehicle.h"


namespace my_racing {
    enum class RaceType
    {
        Ground = 1,
        Air,
        Mixed
    };

	class RACINGLIBRARY Race
	{
	private:
        RaceType type;
        int distance;
        std::vector<std::unique_ptr<Vehicle>> vehicles;
        std::string status;
        std::string raceResults {};

	public:
        Race(RaceType type, int distance);

        Race(const Race&) = delete;
        Race& operator=(const Race&) = delete;

        Race(Race&&) = default;
        Race& operator=(Race&&) = default;


        bool canRegister(const Vehicle& vehicle) const;

        bool registerVehicle(std::unique_ptr<Vehicle> vehicle);

        bool isRegistered(const Vehicle& vehicle) const;

        std::string showVehicles() const;

        RaceType getType() const;
        std::string getTypeName() const;

        int getDistanse() const;

        std::size_t getCountVehicles() const;

        void setStatus(std::string);
        std::string getStatus() const;

        std::string getResult() const;

        void start();
	};
}
