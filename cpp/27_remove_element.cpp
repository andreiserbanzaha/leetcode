#include <vector>

class Solution
{
public:
    int removeElement(std::vector<int> &nums, int val)
    {
        int k = 0;
        int i = 0;
        int last = nums.size() - 1;

        while (i <= last)
        {
            if (nums[i] != val)
            {
                ++i;
                ++k;
                continue;
            }

            nums[i] = nums[last];
            --last;
        }

        return k;
    }
};

int main()
{
    std::vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
    Solution s;
    s.removeElement(nums, 2);
    return 0;
}