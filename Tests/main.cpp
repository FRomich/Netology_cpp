#include <vector>


#include <iostream>
#include <stack>
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

    static bool isValid(std::string s) 
    {
        std::stack<char> st;

        for (char c : s)
        {
            switch (c)
            {
            case '(':
            case '[':
            case '{':
                st.push(c);
                break;

            case ')':
                if (st.empty() || st.top() != '(')
                    return false;
                st.pop();
                break;

            case ']':
                if (st.empty() || st.top() != '[')
                    return false;
                st.pop();
                break;

            case '}':
                if (st.empty() || st.top() != '{')
                    return false;
                st.pop();
                break;
            }
        }

        return st.empty();
    }

    struct ListNode
	{
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}

        ListNode(std::initializer_list<int> values)
        {
            auto it = values.begin();

            if (it == values.end())
            {
                val = 0;
                next = nullptr;
                return;
            }

            val = *it++;
            next = nullptr;

            ListNode* current = this;

            while (it != values.end())
            {
                current->next = new ListNode(*it++);
                current = current->next;
            }
        }
    };

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
	{
        ListNode head;
    	ListNode* current = &head;

        while (list1 && list2)
        {
			if (list1->val <= list2->val)
			{
                current->next = list1;
                list1 = list1->next;
			}
			else
			{
                current->next = list2;
                list2 = list2->next;
			}
            current = current->next;
        }

        current->next = list1 ? list1 : list2;

        return head.next;
    }

    std::ostream& operator<<(std::ostream& os, const ListNode* node)
    {
        while (node)
        {
            os << node->val;

            if (node->next)
                os << ", ";

            node = node->next;
        }

        return os;
    }

    static int removeDuplicates(std::vector<int>& nums)
	{
        if (nums.empty())
            return 0;

        int currentNum = 0;

        for (size_t i = 1; i < nums.size(); ++i)
        {
            if (nums[currentNum] != nums[i])
            {
                ++currentNum;
                nums[currentNum] = nums[i];
            }
        }

    	return currentNum + 1;
    }

    std::ostream& operator<<(std::ostream& os, const std::vector<int>& v)
    {
        os << '[';

        for (size_t i = 0; i < v.size(); ++i)
        {
            if (i > 0)
                os << ", ";

            os << v[i];
        }

        os << ']';

        return os;
    }
}



int main()
{
    std::cout << std::boolalpha;
    std::vector<int> numsSort{ 2, 7, 11,11, 15, 15 };
    std::vector<std::string> vecString {"sasxaasas", "sasxaasa", "sasxamnhng"};
    ListNode firstList{1,2,4};
    ListNode secondList{ 1,3,4 };
 
	std::cout << "twoSum: " << twoSum(numsSort, 18) << "\n";
    std::cout << "isPalindrome: " << isPalindrome(11155111) << "\n";
    std::cout << "longestCommonPrefix: " << longestCommonPrefix(vecString) << "\n";
    std::cout << "isValid: " << isValid("{[()]}()") << "\n";
    std::cout << "mergeTwoLists: " << mergeTwoLists(&firstList, &secondList) << "\n";
	std::cout << "removeDuplicates: " <<removeDuplicates(numsSort) << "\n";
    std::cout << "romanToInt: " << romanToInt("MCMXCIV") << "\n";
}
