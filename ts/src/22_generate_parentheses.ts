function backtrack(
    n: number,
    results: string[],
    curr: string,
    open: number,
    closed: number): void {

    if (open === n && closed == n) {
        results.push(curr);
        return;
    }

    if (open < n) {
        backtrack(n, results, curr + "(", open + 1, closed);
    }
    if (closed < open) {
        backtrack(n, results, curr + ")", open, closed + 1);
    }

}

function generateParenthesis(n: number): string[] {

    let results: string[] = [];

    let open: number = 0;
    let closed: number = 0;

    backtrack(n, results, "", open, closed);

    return results;
};

{
    const a: string[] = generateParenthesis(3); // ["((()))","(()())","(())()","()(())","()()()"]
    const b: string[] = generateParenthesis(1); // ["()"]
}