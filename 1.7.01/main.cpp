#include <iostream>

int main()
{
    std::setlocale(LC_ALL, "Russian");

    short varShort;
    int varInt;
    long varLong;
    long long varLongLong;
    float varFloat;
    double varDouble;
    long double varLongDouble;
    bool varBool;

    std::cout << "short: " << &varShort << " " << sizeof(varShort) << "\n";
    std::cout << "int: " << &varInt << " " << sizeof(varInt) << "\n";
    std::cout << "long: " << &varLong << " " << sizeof(varLong) << "\n";
    std::cout << "long long: " << &varLongLong << " " << sizeof(varLongLong) << "\n";
    std::cout << "float: " << &varFloat << " " << sizeof(varFloat) << "\n";
    std::cout << "double: " << &varDouble << " " << sizeof(varDouble) << "\n";
    std::cout << "long double: " << &varLongDouble << " " << sizeof(varLongDouble) << "\n";
    std::cout << "bool: " << &varBool << " " << sizeof(varBool) << "\n";
}