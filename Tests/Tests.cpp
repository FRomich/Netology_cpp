#include <vector>


#include <iostream>
#include <string>
#include <unordered_map>

namespace
{

    static std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); ++i)
        {
            int complement = target - nums[i];

            auto it = map.find(complement);
            if (it != map.end())
            {
                return { it->second, i };
            }
            map[nums[i]] = i;
        }
        return  {};
    }

    static bool isPalindrome(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reversedHalf = 0;

        while (x > reversedHalf)
        {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        return x == reversedHalf || x == reversedHalf / 10;
    }

    static int romanToInt(std::string s)
	{
        int result = 0;
        for (size_t i = 0; i < s.size(); ++i)
        {
            char next = (i + 1 < s.size()) ? s[i + 1] : '\0';
            switch (s[i])
            {
            case 'I':
                switch (next)
                {
                case 'V':
                    result += 4;
                    ++i;
                    break;
                case 'X':
                    result += 9;
                    ++i;
                    break;
                default:
                    result += 1;
                    break;
                }
                break;
            case 'V':
                result += 5;
                break;
            case 'X':
                switch (next)
                {
                case 'L':
                    result += 40;
                    ++i;
                    break;
                case 'C':
                    result += 90;
                    ++i;
                    break;
                default:
                    result += 10;
                    break;
                }
                break;
            case 'L':
                result += 50;
                break;
            case 'C':
               switch (next)
               {
               case 'D':
                   result += 400;
                   ++i;
                   break;
               case 'M':
                   result += 900;
                   ++i;
                   break;
               default:
                   result += 100;
                   break;
               }
                break;
            case 'D':
                result += 500;
                break;
            case 'M':
                result += 1000;
                break;
            default:
                break;
            }
        }
        return result;
    }

    static std::string longestCommonPrefix(std::vector<std::string>& strs)
	{
        std::string prfx{};
        size_t n = 0;
        while (true)
	    {
            if (n >= strs[0].size()) return prfx;

        	for (size_t i = 1; i < strs.size(); ++i)
            {
                if (n >= strs[i].size() || strs[i][n] != strs[0][n]) return prfx;
                  
            }
            prfx.push_back(strs[0][n]);
            ++n;
        }
    }
}



int main()
{
    
    std::cout << romanToInt("MCMXCIV");
}
