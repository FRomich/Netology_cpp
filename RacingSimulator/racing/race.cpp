#include "race.h"

#include <algorithm>
#include <iomanip>
#include <sstream>

namespace my_racing
{
    Race::Race()    
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

    void Race::setType(RaceType setType)
    {
        type = setType;
    };

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
            return "";
        }
    }

    int Race::getDistanse() const
    {
        return distance;
    };

    void Race::setDistanse(int dist)
    {
        distance = dist;
    }

    std::size_t Race::getCountVehicles() const
    {
        return static_cast<int>(vehicles.size());
    }

    void Race::setStage(StageRace setStage)
    {
        stage = setStage;
    }


    std::string Race::getStageName() const
    {
	    switch (stage)
	    {
	    case StageRace::SelectRaceType:
            return "Настройка типа гонки";

	    case StageRace::SetDistance:
            return "Настройка дистанции гонки";

	    case StageRace::RegisterVehicles:
            return "Регистрация участников";

	    case StageRace::Ready:
            return "Все готово к гонке";

	    case StageRace::Results:
            return "Гонка проведена";
	    }
        return "";
    }

    Message Race::getMessage() const
    {
        return message;
    }


    std::string Race::getMessageName() const
    {
        switch (message)
        {
        case Message::None:
            return "";

        case Message::InvalidValue:
            return "Некорректное значение";

        case Message::InvalidChoice:
            return "Неверный выбор";

        case Message::NotEnoughVehicles:
            return "Недостаточно транспортных средств";

        case Message::Reregistration:
            return "Повторная регистрация участника";

        case Message::Registration:
            return "Успешная регистрация участника";

        case Message::IncorrectTransportType:
            return "Некорректный тип траспортного средства";

        case Message::RegistrationCompleted:
            return "Список участников сформирован";
        }
        return "";
    }

    std::string Race::getResult() const
    {
        return raceResults;
    }

    void Race::start()
    {
        message = Message::None;
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
                << '\n';
        }

        raceResults = oss.str();

    }

    void Race::setMessage(Message setMessage)
    {
        message = setMessage;
    }


}
