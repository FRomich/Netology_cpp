#include <iostream>

int main()
{
    std::setlocale(LC_ALL, "Russian");

    int number = 0;
	int sum = 0;

    do
    {
        std::cout << "Введите целое число или число '0', чтобы закончить:\n";
        std::cin >> number;
        sum += number;
    }
	while (number != 0);

    std::cout << "Сумма: " << sum;    
}

