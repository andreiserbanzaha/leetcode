function searchMatrix(matrix: number[][], target: number): boolean {
    let top: number = 0;
    let bottom: number = matrix.length - 1;
    const rowLength: number = matrix[0].length;
    while (top <= bottom) {
        const mid: number = Math.floor((top + bottom) / 2);
        if (target > matrix[mid][rowLength - 1]) {
            top = mid + 1;
        } else if (target < matrix[mid][0]) {
            bottom = mid - 1;
        } else {
            break;
        }
    }
    if (top > bottom) {
        return false;
    }

    const row: number[] = matrix[Math.floor((bottom + top) / 2)];
    let left: number = 0;
    let right: number = rowLength - 1;
    while (left <= right) {
        const mid: number = Math.floor((right + left) / 2);
        if (target > row[mid]) {
            left = mid + 1;
        } else if (target < row[mid]) {
            right = mid - 1;
        } else {
            return true;
        }
    }

    return false;
};

{
    const a = searchMatrix([[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]], 3);  // true
    const b = searchMatrix([[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]], 13); // false
    const c = searchMatrix([[1, 3]], 2);                                            // false
    const d = searchMatrix([[1, 3]], 3);                                            // true
    const e = searchMatrix([[1], [3]], 1);                                          // true
    const f = searchMatrix([[1], [3], [5]], 3);                                     // true
}