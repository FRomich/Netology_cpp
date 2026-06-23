#include <iostream>
#include <string>

int main()
{
    std::setlocale(LC_ALL, "Russian");
    std::srand(time(nullptr));

    std::string idxMinNum, idxMaxNum;
    int maxNumber = std::numeric_limits<int>::min();
    int minNumber = std::numeric_limits<int>::max();
    const int col = 6, row = 3;
    int arrayNumbers[col][row];

    std::cout << "Массив:\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arrayNumbers[i][j] = std::rand() % 100;
            std::cout << arrayNumbers[i][j] << "\t";
            if (arrayNumbers[i][j] > maxNumber)
            {
                idxMaxNum = std::to_string(i) + " " + std::to_string(j);
                maxNumber = arrayNumbers[i][j];
            }
            if (arrayNumbers[i][j] < minNumber)
            {
                idxMinNum = std::to_string(i) + " " + std::to_string(j);
                minNumber = arrayNumbers[i][j];
            }
        }
        std::cout << "\n";
    }

    std::cout << "Индекс минимального элемента: " << idxMinNum << "\n";
    std::cout << "Индекс максимального элемента: " << idxMaxNum << "\n";
}
