#include <iostream>

#include "Leaver.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    std::string name;
    std::cout << "Введите имя: ";
    std::cin >> name;

    my_leaver::Leaver leaver;
    std::cout << leaver.leave(name);
}
