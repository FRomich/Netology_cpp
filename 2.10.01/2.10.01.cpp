#include <iostream>

#include "Greeter.h"
int main()
{
    setlocale(LC_ALL, "Russian");

    std::string name;
    std::cout << "Введите имя: ";
    std::cin >> name;

    my_greeter::Greeter greeter;
    std::cout << greeter.greet(name);
}

