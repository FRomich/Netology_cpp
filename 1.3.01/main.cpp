#include <iostream>

int main()
{
    std::setlocale(LC_ALL, "Russian");

    bool varBool = true;

    std::cout << std::boolalpha;
    std::cout << "Оператор: ||\n";
    std::cout << varBool << '\t' << varBool << '\t' << (varBool || varBool) << '\n';
    std::cout << !varBool << '\t' << varBool << '\t' << (!varBool || varBool) << '\n';
    std::cout << varBool << '\t' << !varBool << '\t' << (varBool || !varBool) << '\n';
    std::cout << !varBool << '\t' << !varBool << '\t' << (!varBool || !varBool) << '\n';
    std::cout << '\n';
    std::cout << "Оператор: &&\n";
    std::cout << varBool << '\t' << varBool << '\t' << (varBool && varBool) << '\n';
    std::cout << !varBool << '\t' << varBool << '\t' << (!varBool && varBool) << '\n';
    std::cout << varBool << '\t' << !varBool << '\t' << (varBool && !varBool) << '\n';
    std::cout << !varBool << '\t' << !varBool << '\t' << (!varBool && !varBool) << '\n';
}

