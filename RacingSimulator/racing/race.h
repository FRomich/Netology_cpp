#pragma once

#include <memory>
#include <vector>
#include <string>

#include "vehicle.h"


namespace my_racing {
    enum class RaceType
    {
        None,
        Ground,
        Air,
        Mixed
    };

    enum class StageRace
    {
        SelectRaceType,
        SetDistance,
        RegisterVehicles,
        Ready,
        Results
    };

    enum class Message
    {
        None,
        NotEnoughVehicles,
        InvalidValue,
        InvalidChoice,
        Reregistration,
        Registration,
        IncorrectTransportType,
        RegistrationCompleted
    };

	class RACINGLIBRARY Race
	{
	private:
        RaceType type {RaceType::None};
        int distance {0};
        std::vector<std::unique_ptr<Vehicle>> vehicles;
        StageRace stage {StageRace::SelectRaceType};
        Message message {Message::None};
        std::string raceResults {}; 

	public:
        Race();

        Race(const Race&) = delete;
        Race& operator=(const Race&) = delete;

        Race(Race&&) = default;
        Race& operator=(Race&&) = default;

        bool canRegister(const Vehicle&) const;

        bool registerVehicle(std::unique_ptr<Vehicle>);

        bool isRegistered(const Vehicle&) const;

        std::vector<std::string> getVehicleNames() const;

        RaceType getType() const;
        std::string getTypeName() const;
        void setType(RaceType);

        int getDistanse() const;
        void setDistanse(int);

        std::size_t getCountVehicles() const;

        std::string getResult() const;

        void start();
        
        std::string getStageName() const;
        void setStage(StageRace);

        std::string getMessageName() const;
        Message getMessage() const;
        void setMessage(Message);
	};
}
