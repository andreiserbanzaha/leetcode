function maxArea(height: number[]): number {
    let maxArea: number = 0;
    let left: number = 0;
    let right: number = height.length - 1;
    while (left < right) {
        const currArea = Math.min(height[left], height[right]) * (right - left);
        if (currArea > maxArea) {
            maxArea = currArea;
        }
        if (height[left] > height[right]) {
            --right;
        }
        else {
            ++left;
        }
    }
    return maxArea;
};

{
    const a: number = maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7]); // 49
}
