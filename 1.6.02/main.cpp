#include <iostream>

void myPow(int value, int power)
{
	int result = 1;

	for (int i = 0; i < power; i++)
	{
		result *= value;
	}

	std::cout << value << " в степени " << power << " = " << result << "\n";
}

int main()
{
	std::setlocale(LC_ALL, "Russian");

	int value = 5, power = 2;

    myPow(value, power);
    
	value = 3;
	power = 3;

	myPow(value, power);
	
	value = 4;
	power = 4;

	myPow(value, power);
}
