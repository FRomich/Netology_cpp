#include <iostream>
#include <fstream>

int main()
{
    std::ifstream fileIn("in.txt");
    int countsElements = 0;

    if (!fileIn)
    {
        std::cout << "Cannot open file.\n";
        fileIn.close();
        return 1;
    }

    if (!(fileIn >> countsElements))
    {
        std::cout << "Incorrect number of elements";
        fileIn.close();
        return 1;
	    
    }

    int* arrayElements = new int[countsElements];

    for (int i = 0; i < countsElements; ++i)
    {
	    if (!(fileIn >> arrayElements[i]))
	    {
            std::cout << "Incorrect element reading";
            delete[] arrayElements;
            fileIn.close();
            return 1;
	    }
    }

    for (int i = countsElements - 1; i >= 0; --i)
    {
        std::cout << arrayElements[i] << " ";
    }

    delete[] arrayElements;
    fileIn.close();

    return 0;
}
