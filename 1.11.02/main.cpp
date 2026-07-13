#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string mysteryWord {"малина"};
    std::string userWord;

    while (true)
    {
        std::cout << "Введите слово: ";
        std::cin >> userWord;

        if (userWord == mysteryWord)
            break;

        std::cout << "Неправильно\n";
    }

    std::cout << "Правильно! Вы победили! Загаданное слово — " << mysteryWord;
}