#include "consoleUI.h"
#include <iostream>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

ConsoleUI::ConsoleUI()
{
}

void ConsoleUI::clear()
{ 
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void ConsoleUI::show(std::string_view text)
{
    std::cout << text;
}

int ConsoleUI::getKey()
{
#ifdef _WIN32
    return _getch(); 
#else
    termios oldSettings{};
    termios newSettings{};

    tcgetattr(STDIN_FILENO, &oldSettings);

    newSettings = oldSettings;
    newSettings.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);

    int key = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);

    return key;
#endif
}

void ConsoleUI::getAnyKey()
{
#ifdef _WIN32
    _getch();
#else
    getchar();
#endif
}

int ConsoleUI::getInt()
{
    int value;

    while (!(std::cin >> value))
    {
        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );

        std::cout << "Введите целое число: ";
    }

    return value;
}

void ConsoleUI::draw(const RaceView& view)
{
    clear();

    std::cout
        << "====================================\n"
        << "      ГОНОЧНЫЙ СИМУЛЯТОР\n"
        << "====================================\n";

    std::cout << "Тип гонки: " << view.raceType << '\n';

    if (view.distance > 0)
    {
        std::cout << "Дистанция: "
            << view.distance
            << " км\n";
    }

    if (!view.vehicles.empty())
    {
        std::cout << "Участники:\n";

        for (const auto& vehicle : view.vehicles)
        {
            std::cout << "  " << vehicle << '\n';
        }
    }

    std::cout
        << "====================================\n"
        << "Статус: " << view.status << '\n'
        << "====================================\n";

    if (!view.result.empty())
    {
        std::cout << "Результаты гонки:\n"
            << view.result
            << "====================================\n";
    }
}

