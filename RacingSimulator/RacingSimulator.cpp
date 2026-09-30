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
#include "race_view.h"

#include "consoleUI.h"


void setRaceType(my_racing::RaceType& raceType, IUI& ui);

int setDistance(IUI& ui);

void registerVehicles(my_racing::Race& race, IUI& ui);

int getKey();

RaceView makeRaceView(const my_racing::Race& race);

int main()
{
    setlocale(LC_ALL, "");

    std::unique_ptr<IUI> ui = std::make_unique<ConsoleUI>();

    ui->clear();

    ui->show("Добро пожаловать в гоночный симулятор!\n");

    ui->show("Для продолжения нажмите любую клавишу...\n");
    ui->getAnyKey();

    while (true)
    {
        ui->clear();

        my_racing::RaceType raceType;

        setRaceType(raceType, *ui);

        int distance = setDistance(*ui);

        my_racing::Race race(raceType, distance);

        while (race.getCountVehicles() < 2 || race.getStatus() != "Список участников сформирован") //поправить на enum
        {
            ui->draw(makeRaceView(race));

            registerVehicles(race, *ui);
        }

        ui->draw(makeRaceView(race));

        ui->show("Для продолжения нажмите любую клавишу...\n");
        ui->getAnyKey();

        race.start();

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

void setRaceType(my_racing::RaceType& raceType, IUI& ui)
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
			raceType = my_racing::RaceType::Ground;
			break;

		case 2:
			raceType = my_racing::RaceType::Air;
			break;

		case 3:
			raceType = my_racing::RaceType::Mixed;
			break;

		default:
            ui.show("Неверный выбор. Попробуйте ещё раз.\n\n");
			continue;
		}
		break;
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
            race.setStatus("Должно быть не менее 2 участников");
        else 
            race.setStatus("Список участников сформирован");
        return;

    default:
        race.setStatus("Неверный выбор.");
        return;
    }

    std::string name = vehicle->getName();

    if (race.isRegistered(*vehicle))
    {
        race.setStatus(name + " уже зарегистрирован.");
        return;
    }

    if (race.registerVehicle(std::move(vehicle)))
    {
        race.setStatus(name + " успешно зарегистрирован.");
    }
    else
    {
        race.setStatus("Попытка зарегистрировать неправильный тип транспортного средства.");
    }
}

RaceView makeRaceView(const my_racing::Race& race)
{
    RaceView view;

    view.raceType = race.getTypeName();
    view.distance = race.getDistanse();
    view.vehicles = race.getVehicleNames();
    view.status = race.getStatus();
    view.result = race.getResult();

    return view;
}