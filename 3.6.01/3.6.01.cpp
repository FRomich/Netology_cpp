#include <iostream>

int simple_string_hash(std::string str) {
    int sum = 0;

    for (auto s : str) {
        sum += s;
    }

    return sum;
}

unsigned long long real_string_hash(std::string str, unsigned long long p, unsigned long long k) {
    size_t size = str.size();
    unsigned long long sum = 0;
    
    for (size_t idx = 0; idx < size; ++idx)
    {
        sum += str[idx] * std::pow(p, idx);
    };

    return sum % k;
}

int main()
{
    std::string str;
    unsigned long long p = 29;
    unsigned long long k = 1000;

#if 0
    std::cout << "Enter a prime number: ";
    std::cin >> p;
    std::cout << "Enter the module: ";
    std::cin >> k;
#endif

    while (true)
    {
        std::cout << "Enter a string (0 - exit): ";
        std::cin >> str;
        if (str == "0") break;
        std::cout << "Naive string hash \"" << str << "\" = " << simple_string_hash(str) <<'\n';
        std::cout << "Real string hash \"" << str << "\" = " << real_string_hash(str, p, k) <<'\n';


    } 
    std::cout << "Bye\n";
}
