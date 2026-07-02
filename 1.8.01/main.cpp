#include <iostream>

void counting_function()
{
    static int i = 1;
    std::cout << "Количество вызовов функции counting_function(): " << i++ << "\n";
}

int main(int argc, char** argv)
{
    std::setlocale(LC_ALL, "Russian");

    for (int i = 0; i < 15; i++)
    {
        counting_function();
    }
}
