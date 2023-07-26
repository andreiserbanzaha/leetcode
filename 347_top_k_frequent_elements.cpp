#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k)
    {
        std::unordered_map<int, int> map;
        for (int num : nums)
        {
            ++map[num];
        }

        std::vector<std::vector<int>> buckets;
        buckets.resize(nums.size() + 1);

        for (const auto &el : map)
        {
            buckets[el.second].push_back(el.first);
        }

        std::vector<int> res;
        res.reserve(k);
        for (int i = buckets.size() - 1; i >= 0; --i)
        {
            const auto &bucket = buckets[i];
            if (bucket.empty())
            {
                continue;
            }

            for (int num : bucket)
            {
                res.push_back(num);
            }

            if (res.size() == k)
            {
                break;
            }
        }

        return res;
    }
};

int main()
{
    Solution s;

    std::vector<int> nums1{1, 1, 1, 2, 2, 3};
    const auto resNums1 = s.topKFrequent(nums1, 2);

    std::vector<int> nums2{1};
    const auto resNums2 = s.topKFrequent(nums2, 1);

    return 0;
}