#include <iostream>

namespace
{
    static int simple_string_hash(const std::string& str, size_t count) {

        if (str.size() < count) return -1;

        int sum = 0;

        for (size_t i = 0; i < count; ++i) {
            sum += str[i];
        }

        return sum;
    }

    static bool check_characters(const std::string& str, const std::string& substr, size_t idx)
    {
        for (size_t i = 0; i < substr.size(); ++i)
        {
            if (str[idx + i] != substr[i])
                return false;
        }
        return true;
    }

    static int find_substring_light_rabin_karp(const std::string& str, const std::string& substr)
    {
        size_t strSize = str.size();
        size_t substrSize = substr.size();

        if (substrSize == 0 || strSize < substrSize) return -1;

        int hashSubstr = simple_string_hash(substr, substrSize);
        int hashTemp = simple_string_hash(str, substrSize);

        for (size_t i = 0; i <= strSize - substrSize; ++i)
        {
            if (hashSubstr != hashTemp)
            {
                hashTemp -= str[i];
                hashTemp += str[i + substrSize];
                continue;
            }

            if (check_characters(str, substr, i))
                return i;
        }


        return -1;
    }
}

int main()
{
    std::string str, substr;

    std::cout << "Enter the string in which the search will be performed: ";
    std::cin >> str;

    while (true)
    {
        std::cout << "Enter the substring to find (0 - exit): ";
        std::cin >> substr;

        int idx = find_substring_light_rabin_karp(str, substr);

        if (idx == -1)
            std::cout << "Substring \"" << substr << "\" not found \n";
        else
        {
            std::cout << "Substring \"" << substr << "\" found at index " << idx << '\n';
        }

        if (substr == "0") break;
    }

    std::cout << "Bye\n";
}
