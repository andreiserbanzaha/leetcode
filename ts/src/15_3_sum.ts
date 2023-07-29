function threeSum(nums: number[]): number[][] {

    let answer: number[][] = [];
    nums = nums.sort((n1, n2) => n1 - n2);

    for (let i: number = 0; i < nums.length - 2; ++i) {
        if (nums[i - 1] !== undefined && nums[i] === nums[i - 1]) continue;
        let left: number = i + 1;
        let right: number = nums.length - 1;
        while (left < right) {
            const curr = nums[i] + nums[left] + nums[right];
            if (curr > 0) --right;
            else if (curr < 0) ++left;
            else {
                answer.push([nums[i], nums[left], nums[right]]);
                while (nums[left] === nums[++left] && left < right) continue;
            }
        }
    }

    return answer;
};

{
    const a = threeSum([-1, 0, 1, 2, -1, -4]);
    const b = threeSum([0, 1, 1]);
    const c = threeSum([0, 0, 0]);
    const d = threeSum([0, 0, 0, 0]);
    const e = threeSum([-1, 0, 1, 0]);
}