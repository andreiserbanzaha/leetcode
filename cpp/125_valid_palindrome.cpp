#include <string>
#include <iostream>
#include <cctype>

class Solution
{
public:
    bool isPalindrome(std::string s)
    {
        int l = 0;
        int r = s.length() - 1;
        while (l < r)
        {
            if (!std::isalnum(s[l]))
            {
                ++l;
                continue;
            }

            if (!std::isalnum(s[r]))
            {
                --r;
                continue;
            }

            if (std::tolower(s[l]) != std::tolower(s[r]))
            {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
};

int main()
{
    Solution s;
    std::cout << s.isPalindrome("A man, a plan, a canal: Panama") << '\n';
    std::cout << s.isPalindrome("plm") << '\n';

    return 0;
}