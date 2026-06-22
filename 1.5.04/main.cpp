#include <iostream>

int main()
{
    std::setlocale(LC_ALL, "Russian");
    std::srand(time(nullptr));

    const int sizeArray = 10;
    int arrayNumbers[sizeArray];

    for (int i = 0; i < sizeArray; i++)
    {
        arrayNumbers[i] = std::rand() % 100;

    }

    std::cout << "Массив до сортировки: ";
    for (int i = 0; i < sizeArray; i++)
    {
        std::cout << arrayNumbers[i] << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < sizeArray - 1; i++)
    {
        for (int j = 0; j < sizeArray - 1 - i; j++)
        {
            if (arrayNumbers[j] > arrayNumbers[j + 1])
            {
                std::swap(arrayNumbers[j], arrayNumbers[j + 1]);
            }
        }
    }

    std::cout << "Массив после сортировки: ";
    for (int i = 0; i < sizeArray; i++)
    {
        std::cout << arrayNumbers[i] << " ";
    }
    std::cout << "\n";

}
