#include <vector>
#include <unordered_map>

// class Solution
// {
// public:
//     std::vector<int> twoSum(std::vector<int> &nums, int target)
//     {
//         for (int i = 0; i < nums.size() - 1; ++i)
//         {
//             for (int j = i + 1; j < nums.size(); ++j)
//             {
//                 if (nums[i] + nums[j] == target)
//                 {
//                     return {i, j};
//                 }
//             }
//         }
//         return {};
//     }
// };

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i)
        {
            const int needs = target - nums[i];
            if (map.count(needs) > 0)
            {
                return {map[needs], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    std::vector<int> nums{2,7,11,15};
    const int target = 9;

    Solution s;
    const std::vector<int> res = s.twoSum(nums, target);

    return 0;
}