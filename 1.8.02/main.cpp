#include <iostream>

namespace my_addition
{
	int calc(int x, int y)
	{
		return x + y;
	}
}

namespace my_subtraction
{
	int calc(int x, int y)
	{
		return x - y;
	}
	
}

namespace my_multiplication
{
	int calc(int x, int y)
	{
		return x * y;
	}

}

namespace my_division
{
	int calc(int x, int y)
	{
		return x / y;
	}

}

int main()
{
	std::setlocale(LC_ALL, "Russian");

	int x = 5;
	int y = 9;

	std::cout << "x = " << x << " y = " << y << "\n";
    std::cout << "Сложение: " << my_addition::calc(x, y)<< "\n";
	std::cout << "Вычитание: " << my_subtraction::calc(x, y) << "\n";
	std::cout << "Умножение: " << my_multiplication::calc(x, y) << "\n";
	std::cout << "Деление: " << my_division::calc(x, y) << "\n";
}
