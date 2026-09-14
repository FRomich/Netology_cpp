#include <iostream>

#define MODE 1

#ifndef MODE
#error Needed MODE
#endif

#if MODE == 1

int add(int a, int b)
{
    return a + b;
}

#endif

int main()
{
#if  MODE == 0
    std::cout << "Test mode\n";
#elif MODE == 1 
    std::cout << "Arm mode\n";
    int a, b;

    std::cout << "input 2 numbers: ";
    std::cin >> a >> b;

    std::cout << "Result: " << add(a, b) << '\n';


#else
    std::cout << "Unknown mode\n";
#endif
}
