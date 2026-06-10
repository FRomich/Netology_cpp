#include <iostream>

int main()
{
    std::setlocale(LC_ALL, "Russian");

    int number;

    std::cout << "Введите число:\n";
    std::cin >> number;
    std::cout << "Вы ввели:\n" << number;
}

