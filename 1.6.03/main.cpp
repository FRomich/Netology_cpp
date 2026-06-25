#include <iostream>
#include <string>

std::string numbersFibonacci (int count)
{
    if (count == 0)
    {
        return "";
    }
    else if (count == 1)
    {
        return "0";
    }

    long long previous = 0;
    long long forward = 1;
    std::string result 	{ std::to_string(previous) + " " + std::to_string(forward) + " " };

    for (int i = 2; i < count; i++)
    {
        std::swap(previous, forward);
        forward += previous;
        result += std::to_string(forward) + " ";
    }
    return  result;
}

int main()
{
    std::setlocale(LC_ALL, "Russian");

    int countFibonacci;

    std::cout << "Введите число: ";
    std::cin >> countFibonacci;
    std::cout << "Числа Фибоначчи: " << numbersFibonacci(countFibonacci);
}

