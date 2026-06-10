#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char oneWord[30];

    std::cout << "Введите слово:\n";
    std::cin >> oneWord;
    std::cout << "Вы ввели:\n" << oneWord;
}