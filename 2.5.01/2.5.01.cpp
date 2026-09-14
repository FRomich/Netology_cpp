#include <iostream>
#include "MyCalc.h"

int main()
{
    setlocale(LC_ALL, "RUSSIAN");

    int var1, var2, op;

    std::cout << "Введите первое число :";
    std::cin >> var1;
    std::cout << "Введите второе число :";
    std::cin >> var2;
    std::cout << "Выберите операцию(1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень) :";
    std::cin >> op;

    switch (op)
    {
    case 1:
        std::cout << var1 << " плюс " << var2 << " = " << my_calc::sum(var1, var2)  << "\n";
        break;
    case 2:
        std::cout << var1 << " минус " << var2 << " = " << my_calc::diff(var1, var2) << "\n";
        break;
    case 3:
        std::cout << var1 << " умножить " << var2 << " = " << my_calc::mult(var1, var2) << "\n";
        break;
    case 4:
        std::cout << var1 << " делить " << var2 << " = " << my_calc::div(var1, var2) << "\n";
        break;
    case 5:
        std::cout << var1 << " в степени " << var2 << " = " << my_calc::pow(var1, var2) << "\n";
        break;
    default:
        std::cout << "Не верная операция\n";

    }

}

