#include <iostream>
namespace
{
    static int simple_string_hash(const std::string& str)
    {
        int sum = 0;

        for (auto s : str) {
            sum += s;
        }

        return sum;
    }

    static unsigned long long real_string_hash(const std::string& str, unsigned long long p, unsigned long long k)
    {
        unsigned long long sum = 0;
        unsigned long long p_power = 1;

        for (char c : str)
        {
            unsigned long long char_val = static_cast<unsigned char>(c);

            sum = (sum + char_val * p_power) % k;
            p_power = (p_power * p) % k;
        }

        return sum;
    }
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
