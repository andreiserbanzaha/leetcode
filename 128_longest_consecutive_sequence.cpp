#include <vector>
#include <set>
#include <iostream>

class Solution
{
public:
    int longestConsecutive(std::vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        std::set<int> set;

        for (int num : nums)
        {
            set.insert(num);
        }

        auto prev = set.begin();
        auto it = set.begin();
        ++it;

        std::vector<int> longest;
        longest.push_back(1);
        int i = 0;

        for (; it != set.end(); ++it)
        {
            if (*it == *prev + 1)
            {
                ++longest[i];
            }
            else
            {
                longest.push_back(1);
                ++i;
            }

            prev = it;
        }

        int max = 0;

        for (int val : longest)
        {
            if (val > max)
            {
                max = val;
            }
        }

        return max;
    }
};

int main()
{
    std::vector<int> a{100, 4, 200, 1, 3, 2};         // 4 -> 1, 2, 3, 4
    std::vector<int> b{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}; // 9 -> 0, 1, ..., 8

    Solution s;
    const int resA = s.longestConsecutive(a);
    const int resB = s.longestConsecutive(b);

    return 0;
}