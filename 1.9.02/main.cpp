#include <iostream>

void swap (int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int a = 5;
    int b = 8;

    std::cout << "a = " << a << ", b = " << b << "\n";

    swap(&a, &b);

    std::cout << "a = " << a << ", b = " << b << "\n";
}

