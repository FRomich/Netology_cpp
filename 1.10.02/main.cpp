#include <iostream>

namespace 
{
	int* createDynArrayZero(const int* sizeArray)
	{
        return new int[*sizeArray]{};
	}
}


int main()
{
    std::setlocale(LC_ALL, "Russian");

    int sizeArray;

    std::cout << "Введите размер массива: ";
    std::cin >> sizeArray;

    int* dynArrayZero = createDynArrayZero(&sizeArray);

    std::cout << "Массив: ";
    for (int i = 0; i < sizeArray; i++)
    {
        std::cout << dynArrayZero[i] << " ";
    }

    delete[] dynArrayZero;
}
