#include <iostream>
#include <fstream>

int main()
{
    std::setlocale(LC_ALL, "Russian");

    std::ifstream fileIn("in.txt");
    std::string oneWord;

    if (!fileIn)
    {
        std::cout << "Cannot open file.\n";
        fileIn.close();
        return 1;
    }

    while (fileIn >> oneWord)
    {
        std::cout << oneWord << '\n';
    }

    fileIn.close();
    return 0;
}
