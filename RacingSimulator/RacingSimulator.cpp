#include <iostream>
#include <memory>
#include <cstdlib>
#include <clocale>

#include "all_terrain_boots.h"
#include "broom.h"
#include "camel.h"
#include "carpet_plane.h"
#include "centaur.h"
#include "eagle.h"
#include "fast_camel.h"
#include "race.h"
#include "vehicle.h"
#include "IUI.h"

#include "consoleUI.h"

my_racing::RaceType setRaceType(IUI& ui);

int setDistance(IUI& ui);

void registerVehicles(my_racing::Race& race, IUI& ui);

int getKey();

RaceView makeRaceView(const my_racing::Race& race);

int main()
{
    setlocale(LC_ALL, "");

    std::unique_ptr<IUI> ui = std::make_unique<my_consol::ConsoleUI>();
    
    while (true)
    {
        my_racing::Race race;

        ui->draw(makeRaceView(race));

        race.setType(setRaceType(*ui));
        race.setStage(my_racing::StageRace::SetDistance);

        ui->draw(makeRaceView(race));

        race.setDistanse(setDistance(*ui));
        race.setStage(my_racing::StageRace::RegisterVehicles);

        while (race.getCountVehicles() < 2 ||
            race.getMessage() != my_racing::Message::RegistrationCompleted) 
        {
            ui->draw(makeRaceView(race)); 

            registerVehicles(race, *ui);
        }

        race.setStage(my_racing::StageRace::Ready); 

        ui->draw(makeRaceView(race));

        ui->show("Для проведения гонки нажмите любую клавишу...\n");
        ui->getAnyKey(); //ok

        race.start();
        race.setStage(my_racing::StageRace::Results);

        ui->draw(makeRaceView(race));

        ui->show("Для выхода нажмите \"ESC\", для повторения гонки любую клавишу\n");

        int key = ui->getKey();

        if (key == 27) // ESC
        {
            return EXIT_SUCCESS;
        }
    }
	return EXIT_FAILURE;
}

my_racing::RaceType setRaceType(IUI& ui)
{
	while (true)
	{
        ui.show("1. Гонка для наземного транспорта\n");
        ui.show("2. Гонка для воздушного транспорта\n");
        ui.show("3. Гонка для наземного и воздушного транспорта\n");
        ui.show("Выберите тип гонки: ");

        int choice = ui.getInt();

		switch (choice)
		{
		case 1:
			return  my_racing::RaceType::Ground;
		case 2:
            return my_racing::RaceType::Air;
		case 3:
            return my_racing::RaceType::Mixed;

		default:
            ui.show("Неверный выбор. Попробуйте ещё раз.\n\n");
			continue;
		}
	}
};

int setDistance(IUI& ui)
{
    while (true)
    {
        ui.show("Укажите длину дистанции (должна быть положительной): ");

        int result = ui.getInt();

        if (result > 0)
        {
            return result;
        }

        ui.show("Некорректное значение. Попробуйте ещё раз.\n");
    }
}

void registerVehicles(my_racing::Race& race, IUI& ui)
{
    ui.show(
        "\n1. Верблюд\n"
        "2. Быстрый верблюд\n"
        "3. Кентавр\n"
        "4. Вездеходные ботинки\n"
        "5. Ковер-самолет\n"
        "6. Орел\n"
        "7. Метла\n"
        "\n0. Выход\n"
        "Выберите транспорт или 0 для окончания регистрации: "
    );
    int choice = ui.getInt();

    std::unique_ptr<my_racing::Vehicle> vehicle;

    switch (choice)
    {
    case 1:
        vehicle = std::make_unique<my_racing::Camel>();
        break;

    case 2:
        vehicle = std::make_unique<my_racing::FastCamel>();
        break;

    case 3:
        vehicle = std::make_unique<my_racing::Centaur>();
        break;

    case 4:
        vehicle = std::make_unique<my_racing::AllTerrainBoots>();
        break;

    case 5:
        vehicle = std::make_unique<my_racing::CarpetPlane>();
        break;

    case 6:
        vehicle = std::make_unique<my_racing::Eagle>();
        break;

    case 7:
        vehicle = std::make_unique<my_racing::Broom>();
        break;

    	case 0:

        if (race.getCountVehicles() < 2) 
            race.setMessage(my_racing::Message::NotEnoughVehicles);
        else
        {
	        race.setMessage(my_racing::Message::RegistrationCompleted);            
        }
            
        return;

    default:
        race.setMessage(my_racing::Message::InvalidValue);
        return;

    }

    std::string name = vehicle->getName();

    if (race.isRegistered(*vehicle))
    {
        race.setMessage(my_racing::Message::Reregistration);
        return;
    }

    if (race.registerVehicle(std::move(vehicle)))
    {
        race.setMessage(my_racing::Message::Registration);
    }
    else
    {
        race.setMessage(my_racing::Message::IncorrectTransportType);
    }
}

RaceView makeRaceView(const my_racing::Race& race)
{
    RaceView view;

    view.raceType = race.getTypeName();
    view.distance = race.getDistanse();
    view.vehicles = race.getVehicleNames();
    view.stage = race.getStageName();
    view.message = race.getMessageName();
    view.result = race.getResult();

    return view;
}