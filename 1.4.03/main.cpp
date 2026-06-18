#include <iostream>

int main()
{
    std::setlocale(LC_ALL, "Russian");

    int number = 0;

    std::cout << "Введите целое число:\n";
    std::cin >> number;

    for (int i = 0; i < 10; i++)
    {
        std::cout << number << " x "  << i << " = " << number*i << std::endl;
    }
}