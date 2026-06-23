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
    for (auto el : arrayNumbers)
    {
        std::cout << el << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < sizeArray - 1; i++)
    {
        bool arrayChanged = false;
        for (int j = 0; j < sizeArray - 1 - i; j++)
        {
            if (arrayNumbers[j] > arrayNumbers[j + 1])
            {
                std::swap(arrayNumbers[j], arrayNumbers[j + 1]);
                arrayChanged = true;
            }
        }
        if (!arrayChanged) break;
    }

    std::cout << "Массив после сортировки: ";
    for (auto el : arrayNumbers)
    {
        std::cout << el << " ";
    }
    std::cout << "\n";
}
