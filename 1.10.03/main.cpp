#include <iostream>
#include <iomanip>

namespace
{
    int** createTwoDimArray(const int* rows, const int* cols)
    {
        int** twoDimArray = new int* [*rows];

        for (int i = 0; i < *rows; i++)
        {
            twoDimArray[i] = new int[*cols + 1];
        }

        return twoDimArray;
    }

    void fillTwoDimArray (int** twoDimArray, const int* rows, const int* cols)
	{
        for (int i = 0; i < *rows; i++)
        {
	        for (int j = 0; j < *cols; j++)
	        {
                twoDimArray[i][j] = (i + 1) * (j + 1);
	        }
        }
    }

    void printTwoDimArray(int** twoDimArray, const int* rows, const int* cols)
    {
        std::cout << "Таблица умножения:\n";
        for (int i = 0; i < *rows; i++)
        {
            for (int j = 0; j < *cols; j++)
            {
                std::cout << std::setw(3) << twoDimArray[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    void deleteTwoDimArray(int** twoDimArray, const int* rows, const int* cols)
    {
        for (int i = 0; i < *rows; i++)
        {
            delete[] twoDimArray[i];
        }
        delete[] twoDimArray;
    }       
}


int main()
{
    std::setlocale(LC_ALL, "Russian");

    int rows;
    int cols;

    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;

    int** twoDimArray = createTwoDimArray(&rows, &cols);

    fillTwoDimArray(twoDimArray, &rows, &cols);
    printTwoDimArray(twoDimArray, &rows, &cols);
    deleteTwoDimArray(twoDimArray, &rows, &cols);
}
