#include <string>

class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        int sLetter[26] = {0};
        int tLetter[26] = {0};

        for (const char c : s)
        {
            ++sLetter[c - 'a'];
        }

        for (const char c : t)
        {
            ++tLetter[c - 'a'];
        }

        for (int i = 0; i < 26; ++i)
        {
            if (sLetter[i] != tLetter[i])
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    const bool isAnagram = s.isAnagram("anagram", "nagaram");
    const bool isNotAnagram = s.isAnagram("car", "rat");

    return 0;
}