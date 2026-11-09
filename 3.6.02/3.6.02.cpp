#include <iostream>
#include <string>

int simple_string_hash(std::string str, int count) {
    
    if (str.size() < count) return -1;

    int sum = 0;

    for (size_t i = 0; i < count; ++i) {
        sum += str[i];
    }

    return sum;
}

bool checkСharacter(const std::string& str, const std::string& substr, int idx)
{
    for (int i = 0; i < substr.size(); ++i)
    {
        if (str[idx + i] != substr[i])
            return false;
    }
    return true;
}

int find_substring_light_rabin_karp(std::string str, std::string substr) 
{
    int strSize = str.size();
    int substrSize = substr.size();
    
    if (substrSize == 0 || strSize < substrSize) return -1;

    int hashSubstr = simple_string_hash(substr, substrSize);
    int hashTemp = simple_string_hash(str, substrSize);

    for (size_t i = 0; i <= strSize - substrSize; ++i)
    {
        if (hashSubstr == hashTemp)
        {
            if (checkСharacter(str, substr, i))
                return i;
        }

        if (i < strSize - substrSize)
        {
            hashTemp -= str[i];
            hashTemp += str[i + substrSize];
        }
    }
    

    return - 1;
}

int main()
{
    std::string str, substr;

    std::cout << "Enter the string in which the search will be performed: ";
    std::getline(std::cin, str);

    while (true)
    {
        std::cout << "Enter the substring to find (0 - exit): ";
        std::cin >> substr;

        if (substr == "0") break;

        int idx = find_substring_light_rabin_karp(str, substr);

        if (idx == -1)
            std::cout << "Substring \"" << substr << "\" not found \n";
        else
        {
            std::cout << "Substring \"" << substr << "\" found at index " << idx << '\n';
        }
    }

    std::cout << "Bye\n";
}
