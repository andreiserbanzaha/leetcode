function characterReplacement(s: string, k: number): number {
    let max: number = 0;

    let arr: number[] = [];
    for (let i: number = 0; i < 26; ++i) { arr.push(0); }

    const capitalA: number = "A".charCodeAt(0);

    let l: number = 0;
    let r: number = 0;
    let currMax: number = 0;
    while (r < s.length) {
        const c: number = s.charCodeAt(r) - capitalA;
        ++arr[c];
        currMax = Math.max(arr[c], currMax);
        if ((r - l + 1) - currMax <= k) {
            max = Math.max(r - l + 1, max);
        }

        while ((r - l + 1) - currMax > k) {
            --arr[s.charCodeAt(l) - capitalA];
            ++l;
        }

        ++r;
    }

    return max;
};

{
    const a = characterReplacement("ABAB", 2);      // 4
    const b = characterReplacement("AABABBA", 1);   // 4
}