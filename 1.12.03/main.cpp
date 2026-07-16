#include <iostream>
#include <fstream>

int main()
{
    std::setlocale(LC_ALL, "Russian");

    std::ofstream fileOut("Out.txt");
    int countsElements = 0;

    std::cout << "Введите размер массива: ";
    std::cin >> countsElements;

    int* arrayElements = new int[countsElements];

    for (int i = 0; i < countsElements; ++i)
    {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arrayElements[i];
    }

    fileOut << countsElements << "\n";

    for (int i = countsElements - 1; i >= 0; --i)
    {
        fileOut << arrayElements[i] << " ";
    }
   
    delete[] arrayElements;
    fileOut.close();

    return 0;
}
