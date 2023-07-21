#include <string>

class Solution
{
public:
    int lengthOfLastWord(std::string s)
    {
        int i = s.size() - 1;
        while (s[i] == ' ')
        {
            --i;
        }

        int count = 0;
        while (i >= 0 && s[i] != ' ')
        {
            ++count;
            --i;
        }

        return count;
    }
};

int main()
{
    Solution s;
    const int lolw = s.lengthOfLastWord("a");
    return 0;
}