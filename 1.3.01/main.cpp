#include <iostream>

int main()
{
    std::setlocale(LC_ALL, "Russian");

    bool varBool = true;

    std::cout << "Оператор: ||\n";
    std::cout << std::boolalpha << varBool << '\t' << varBool << '\t' << (varBool || varBool) << '\n';
    std::cout << std::boolalpha << !varBool << '\t' << varBool << '\t' << (!varBool || varBool) << '\n';
    std::cout << std::boolalpha << varBool << '\t' << !varBool << '\t' << (varBool || !varBool) << '\n';
    std::cout << std::boolalpha << !varBool << '\t' << !varBool << '\t' << (!varBool || !varBool) << '\n';
    std::cout << '\n';
    std::cout << "Оператор: &&\n";
    std::cout << std::boolalpha << varBool << '\t' << varBool << '\t' << (varBool && varBool) << '\n';
    std::cout << std::boolalpha << !varBool << '\t' << varBool << '\t' << (!varBool && varBool) << '\n';
    std::cout << std::boolalpha << varBool << '\t' << !varBool << '\t' << (varBool && !varBool) << '\n';
    std::cout << std::boolalpha << !varBool << '\t' << !varBool << '\t' << (!varBool && !varBool) << '\n';
}

