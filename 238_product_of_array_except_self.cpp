#include <vector>

//  1   2   3   4

//  1   1   2   6

//  24  12  8   6

class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        std::vector<int> res(nums.size(), 1);

        int pre = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            res[i] = pre;
            pre *= nums[i];
        }

        int post = nums.back();
        for (int i = res.size() - 2; i >= 0; --i)
        {
            res[i] *= post;
            post *= nums[i];
        }

        return res;
    }
};

int main()
{

    std::vector<int> nums{1, 2, 3, 4}; // [24,12,8,6]
    // std::vector<int> nums{-1, 1, 0, -3, 3};  // [0,0,9,0,0]

    Solution s;
    const auto res = s.productExceptSelf(nums);

    return 0;
}