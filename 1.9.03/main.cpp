#include <iostream>

namespace
{

    static void print(const int* array, int sizeArray)
    {
        while (sizeArray--)
        {
            std::cout << *array++ << " ";
        }
        std::cout << "\n";
    }

    static void reverse(int* array, int sizeArray)
    {
        for (int i = 0; i < sizeArray / 2; i++)
        {
            int temp = array[i];
            array[i] = array[sizeArray - 1 - i];
            array[sizeArray - 1 - i] = temp;
        }
    }
} ///end namespace

int main()
{
    std::setlocale(LC_ALL, "Russian");

    int array[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int sizeArray = std::size(array);

    std::cout << "До функции reverse: ";
    print(array, sizeArray);

    reverse(array, sizeArray);

    std::cout << "После функции reverse: ";
    print(array, sizeArray);
}

