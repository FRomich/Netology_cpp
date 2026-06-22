#include <iostream>

int main()
{
    std::srand(time(nullptr));

    const int sizeArray = 10;
    int arrayNumbers[sizeArray];
    
    for (int i = 0; i<sizeArray; i++)
    {
        arrayNumbers[i] = std::rand() % 100;
        std::cout << arrayNumbers[i];
        std::cout << ((i != sizeArray - 1) ? ", " : "\n");
    }
}
