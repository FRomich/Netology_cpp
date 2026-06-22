#include <iostream>
#include <string>

int main()
{
    std::setlocale(LC_ALL, "Russian");
    std::srand(time(nullptr));

    const int sizeArray = 10;
    int arrayNumbers[sizeArray];
    int maxNumber = std::numeric_limits<int>::min();
	int minNumber = std::numeric_limits<int>::max();
    std::string arrayNumberTaxt;
    
    for (int i = 0; i < sizeArray; i++)
    {
        arrayNumbers[i] = std::rand() % 100;
        if (maxNumber < arrayNumbers[i]) maxNumber = arrayNumbers[i];
        if (minNumber > arrayNumbers[i]) minNumber = arrayNumbers[i];
        arrayNumberTaxt += std::to_string(arrayNumbers[i]) + ((i != sizeArray - 1) ? " " : "\n");
    }

    std::cout << "Массив: " << arrayNumberTaxt;
    std::cout << "Минимальный элемент: " << minNumber << "\n";
    std::cout << "Максимальный элемент: " << maxNumber << "\n";
}
