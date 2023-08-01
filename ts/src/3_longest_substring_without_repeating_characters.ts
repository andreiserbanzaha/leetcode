function lengthOfLongestSubstring(s: string): number {

    if (s.length === 0) return 0;

    let longest: number = 1;
    let i: number = 1;
    let set: Set<string> = new Set();
    set.add(s[0]);
    while (i < s.length) {
        if (!set.has(s[i])) {
            set.add(s[i]);
            ++i;
            continue;
        }

        longest = Math.max(longest, set.size);

        for (let el of set) {
            if (el === s[i]) {
                set.delete(s[i]);
                break;
            }
            set.delete(el);
        }
        set.add(s[i]);
        ++i;
    }
    return Math.max(longest, set.size);
};