#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
    std::ifstream fileIn("in.txt");
    int countsRows = 0;
    int countsCols = 0;

    if (!fileIn)
    {
        std::cout << "Cannot open file.\n";
        fileIn.close();
        return 1;
    }

    if (!(fileIn >> countsRows))
    {
        std::cout << "Incorrect number of rows";
        fileIn.close();
        return 1;

    }

    if (!(fileIn >> countsCols))
    {
        std::cout << "Incorrect number of cols";
        fileIn.close();
        return 1;

    }

    int** arrayElements = new int*[countsRows];

    for (int i = 0; i < countsRows; ++i)
    {
        arrayElements[i] = new int[countsCols];
    }

    for (int i = 0; i < countsRows; ++i)
    {
        for (int j = 0; j < countsCols; j++)
        {
            fileIn >> arrayElements[i][j];
        }

    }

    for (int i = 0; i < countsRows; ++i)
    {
        for (int j = countsCols - 1; j >= 0; j--)
        {
            std::cout << std::setw(2) << arrayElements[i][j] << " ";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < countsRows; ++i)
    {
        delete[] arrayElements[i];
    }

    delete[] arrayElements;

    fileIn.close();

    return 0;
}
