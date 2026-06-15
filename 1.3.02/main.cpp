#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int firstNumber, secondNumber, thirdNumber;

    std::cout << "Введите первое число: ";
    std::cin >> firstNumber;
    std::cout << "Введите второе число: ";
    std::cin >> secondNumber;
    std::cout << "Введите третье  число: ";
    std::cin >> thirdNumber;
    std::cout << "Результат: ";
        (firstNumber >= secondNumber)
        ? ((secondNumber >= thirdNumber)
            ? std::cout << firstNumber << ' ' << secondNumber << ' ' << thirdNumber
            : (firstNumber >= thirdNumber)
            ? std::cout << firstNumber << ' ' << thirdNumber << ' ' << secondNumber
            : std::cout << thirdNumber << ' ' << firstNumber << ' ' << secondNumber)
        : ((firstNumber >= thirdNumber)
            ? std::cout << secondNumber << ' ' << firstNumber << ' ' << thirdNumber
            : (secondNumber >= thirdNumber)
            ? std::cout << secondNumber << ' ' << thirdNumber << ' ' << firstNumber
            : std::cout << thirdNumber << ' ' << secondNumber << ' ' << firstNumber);
}

