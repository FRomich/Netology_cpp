#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string firstName;
    std::string lastName;
    std::string targetString;

    std::cout << "Введите имя: ";
    std::cin >> firstName;
    std::cout << "Введите фамилию: ";
    std::cin >> lastName;

    targetString = "Здравствуйте, " + firstName + " " + lastName + "!";

    std::cout << targetString;
}
