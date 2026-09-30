#include "console_renderer.h"

#include <iostream>

void my_racing::ConsoleRenderer::clear()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void my_racing::ConsoleRenderer::draw(const Race& race)
{
    std::string screen;

    screen += "====================================\n";
    screen += "      ГОНОЧНЫЙ СИМУЛЯТОР\n";
    screen += "====================================\n";
    screen += "    " + race.getTypeName() + "\n";
    screen += "====================================\n";
    if (race.getDistanse() > 0) 
        screen += "Дистанция: " + std::to_string(race.getDistanse()) + " км\n";
    if ( race.getCountVehicles() > 0)
   // screen += "Участники: " + race.showVehicles() + "\n";
    screen += "====================================\n";
    screen += "Статус: " + race.getStatus() + "\n";
    screen += "====================================\n";
    if (!race.getResult().empty())
    {
        screen += "Результаты гонки: \n";
        screen += race.getResult();
        screen += "====================================\n";
    }

    clear();
    std::cout << screen;
}
