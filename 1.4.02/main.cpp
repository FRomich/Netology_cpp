#include <iostream>
#include <string>

int main()
{
    std::setlocale(LC_ALL, "Russian");

    int number = 0;
    int sumDigit = 0;
    int countDigit = 0;

    std::cout << "Введите целое число:\n";
    std::cin >> number;

    countDigit = std::to_string(abs(number)).length();

    while (countDigit-- > 0 )
    {
        sumDigit += number / pow(10, countDigit);
        number = number % 10;
    }

//    while (number / 10 != 0)
//    {
//        sumDigit += 1;
//        number = number % 10;
//    }
//
//    std::cout << "Сумма цифр: " << sumDigit;
}

