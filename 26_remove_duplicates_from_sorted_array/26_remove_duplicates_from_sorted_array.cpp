#include <vector>

class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return 1;
        }

        if (nums.size() == 2)
        {
            return nums[0] == nums[1] ? 1 : 2;
        }

        int k = 1;
        int i = 1;
        int j = 1;
        int curr = nums[0];

        while (j < nums.size())
        {
            if (curr == nums[j])
            {
                ++j;
                continue;
            }

            nums[i] = nums[j];
            curr = nums[i];
            ++i;
            ++j;
            ++k;
        }
        return k;
    }
};

int main()
{
    std::vector<int> nums{1, 2, 3};
    Solution s;
    int k = s.removeDuplicates(nums);
    return 0;
}