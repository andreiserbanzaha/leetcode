#include <vector>
#include <unordered_set>

class Solution
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        std::unordered_set<int> set;
        for (int num : nums)
        {
            if (set.count(num))
            {
                return true;
            }
            set.emplace(num);
        }
        return false;
    }
};

int main()
{
    std::vector<int> a{1, 2, 3, 1};
    std::vector<int> b{1, 2, 3, 4};

    Solution s;
    const bool x = s.containsDuplicate(a);
    const bool y = s.containsDuplicate(b);

    return 0;
}