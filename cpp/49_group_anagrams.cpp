#include <string>
#include <vector>

// class Solution
// {
// public:
//     std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
//     {
//         std::vector<std::vector<std::string>> groups;
//         std::vector<const int *> letters;

//         for (auto &str : strs)
//         {
//             const int *ltr = createLetters(str);

//             const int pos = getLettersPos(ltr, letters);
//             if (pos >= 0)
//             {
//                 groups[pos].push_back(std::move(str));
//                 continue;
//             }
//             std::vector<std::string> vec{std::move(str)};
//             groups.push_back(std::move(vec));
//             letters.push_back(ltr);
//         }

//         for (auto p : letters)
//         {
//             delete[] p;
//         }

//         return groups;
//     }

// private:
//     int *createLetters(const std::string &s)
//     {
//         int *letters = new int[26];

//         for (const char c : s)
//         {
//             ++letters[c - 'a'];
//         }
//         return letters;
//     }

//     bool isAnagram(const int *aLetters, const int *bLetters)
//     {
//         for (int i = 0; i < 26; ++i)
//         {
//             if (aLetters[i] != bLetters[i])
//             {
//                 return false;
//             }
//         }

//         return true;
//     }

//     int getLettersPos(const int *ltr, const std::vector<const int *> &letters)
//     {
//         for (int i = 0; i < letters.size(); ++i)
//         {
//             if (isAnagram(ltr, letters[i]))
//             {
//                 return i;
//             }
//         }

//         return -1;
//     }
// };

#include <unordered_map>
#include <algorithm>
class Solution
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> map;
        for (auto &&str : strs)
        {
            std::string key = str;
            std::sort(key.begin(), key.end());
            map[key].push_back(std::move(str));
        }

        std::vector<std::vector<std::string>> groups;
        for (auto &&el : map)
        {
            groups.push_back(std::move(el.second));
        }

        return groups;
    }
};

int main()
{
    std::vector<std::string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    // [["bat"],["nat","tan"],["ate","eat","tea"]]

    Solution s;
    const auto res = s.groupAnagrams(strs);

    return 0;
}