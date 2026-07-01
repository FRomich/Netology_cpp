#include <iostream>
#include <string>

std::string numbersFibonacciRecursive(int count, int index = 0, long long a = 0, long long b = 1)
{
	if (index >= count)
		return "";

	return std::to_string(a) + (index + 1 == count ? "" : " ") + numbersFibonacciRecursive(count, index + 1, b, a + b);
}

int main()
{
    std::setlocale(LC_ALL, "Russian");

    int countFibonacci;

    std::cout << "Введите число: ";
    std::cin >> countFibonacci;

    std::cout << "Числа Фибоначчи: " << numbersFibonacciRecursive(countFibonacci) << "\n";
}

