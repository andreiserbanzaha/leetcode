
function twoSum(numbers: number[], target: number): number[] {

    let left: number = 0;
    let right: number = numbers.length - 1;

    let curr: number = numbers[left] + numbers[right];
    while (curr != target) {
        if (curr > target) {
            --right;
        } else {
            ++left;
        }
        curr = numbers[left] + numbers[right];
    }

    return [left + 1, right + 1];
};

{
    const a = twoSum([2, 7, 11, 15], 9);
    const b = twoSum([2, 3, 4], 6);
}

// -5 -3 -2 0 1 2 5 7 10 11 15 