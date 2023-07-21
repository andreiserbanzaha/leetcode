#include <string>

class Solution
{
public:
    int strStr(std::string haystack, std::string needle)
    {
        const char c = needle[0];
        for (int i = 0; i < haystack.size(); ++i)
        {
            if (haystack[i] != c)
            {
                continue;
            }

            if (isFullString(&(haystack[i]), needle.data()))
            {
                return i;
            }
        }
        return -1;
    }

private:
    bool isFullString(char const *haystack, char const *needle)
    {
        while (*needle && *haystack)
        {
            if (*needle != *haystack)
            {
                return false;
            }
            ++haystack;
            ++needle;
        }
        return *needle == '\0';
    }
};

int main()
{
    Solution s;
    const int pos = s.strStr("aaa", "aaaa");

    return 0;
}