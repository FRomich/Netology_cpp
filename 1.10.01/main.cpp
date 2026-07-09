#include <iostream>
#include <windows.h>


int main()
{
    std::setlocale(LC_ALL, "Russian");

    int sizeArray;

    std::cout << "Введите размер массива: ";
    std::cin >> sizeArray;

    int* dynArray = new int[sizeArray];
     
    for (int i = 0; i < sizeArray; i++)
    {
        std::cout <<  "arr[" << i << "] = ";
        std::cin >> dynArray[i];
    }

    std::cout << "Введённый массив: ";
    for (int i = 0; i < sizeArray; i++)
    {
        std::cout << dynArray[i] << " ";
    }

    delete[] dynArray;
}

