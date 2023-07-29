function search(nums: number[], target: number): number {
    let left: number = 0;
    let right: number = nums.length - 1;

    while (left <= right) {
        const mid = Math.floor((right + left) / 2);
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
};

{
    const a = search([-1, 0, 3, 5, 9, 12], 9);  // 4
    const b = search([-1, 0, 3, 5, 9, 12], 2);  // -1
    const c = search([5], 5);  // 0
    const d = search([2, 5], 5);  // 1
}

// -1 0 3 5 9 12
//  0 1 2 3 4 5
// mid = 3
// left = 4
// right = 5