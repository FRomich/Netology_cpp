#include <iostream>
#include <memory>
#include <stdlib.h>
#include <vector>
#include <conio.h>

#include "all_terrain_boots.h"
#include "broom.h"
#include "camel.h"
#include "carpet_plane.h"
#include "centaur.h"
#include "eagle.h"
#include "fast_camel.h"
#include "race.h"
#include "vehicle.h"
#include "console_renderer.h"

void setRaceType(my_racing::RaceType& raceType);

int setDistance();

void registerVehicles(my_racing::Race& race);

int main()
{
	setlocale(LC_ALL, "Russian");

    std::cout << "Добро пожаловать в гоночный симулятор!\n";
    std::cout << "Для продолжения нажмите любую клавишу...\n";
    _getch();

    while (true)
    {
        my_racing::RaceType raceType;

        setRaceType(raceType);

        int distance = setDistance();

        my_racing::Race race(raceType, distance);

        while (race.getCountVehicles() < 2 || race.getStatus() != "Список участников сформирован")
        {
            my_racing::ConsoleRenderer::draw(race);

            registerVehicles(race);
        }

        my_racing::ConsoleRenderer::draw(race);

        std::cout << "Для проведения гонки нажмите любую клавишу...\n";
        _getch();

        race.start();

        my_racing::ConsoleRenderer::draw(race);

        std::cout << "Для выхода нажмите \"ESC\", для повторения гонки любую клавишу\n";

        int key = _getch();

        if (key == 27) // ESC
        {
            return EXIT_SUCCESS;
        }
    }
	return EXIT_FAILURE;
}

void setRaceType(my_racing::RaceType& raceType)
{
	int choice;
    my_racing::ConsoleRenderer::clear();

	while (true)
	{
		std::cout << "1. Гонка для наземного транспорта\n";
		std::cout << "2. Гонка для воздушного транспорта\n";
		std::cout << "3. Гонка для наземного и воздушного транспорта\n";
		std::cout << "Выберите тип гонки: ";

		std::cin >> choice;

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
			std::cout << "Неверный выбор. Попробуйте ещё раз.\n\n";
			continue;
		}
		break;
	}
};

int setDistance()
{
    int result;

    while (true)
    {
        std::cout << "Укажите длину дистанции (должна быть положительной): ";

        if (std::cin >> result && result > 0)
        {
            return result;
        }

        std::cout << "Некорректное значение. Попробуйте ещё раз.\n";

        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );
    }
}

void registerVehicles(my_racing::Race& race)
{
    int choice;

    std::cout << "\n1. Верблюд\n";
    std::cout << "2. Быстрый верблюд\n";
    std::cout << "3. Кентавр\n";
    std::cout << "4. Вездеходные ботинки\n";
    std::cout << "5. Ковер-самолет\n";
    std::cout << "6. Орел\n";
    std::cout << "7. Метла\n";
    std::cout << "0. Выход\n";

    std::cout << "Выберите транспорт или 0 для окончания регистрации: ";
    std::cin >> choice;

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