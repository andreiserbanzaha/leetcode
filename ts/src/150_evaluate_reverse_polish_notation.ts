
function getResult(a: number, b: number, operation: string): number {
    switch (operation) {
        case "+": return a + b;
        case "-": return a - b;
        case "*": return a * b;
        case "/": return Math.trunc(a / b);
        default: return 0;
    }
}

function evalRPN(tokens: string[]): number {
    let numbers: number[] = [];
    tokens.forEach(el => {
        if (!isNaN(Number(el))) {
            numbers.push(+el);
            return;
        }
        const last: number = numbers.length - 1;
        numbers[last - 1] = getResult(numbers[last - 1], numbers[last], el);
        numbers.pop();
    });
    return numbers[0];
};

// ((2 + 1) * 3) = 9
const a: number = evalRPN(["2", "1", "+", "3", "*"]);

// (4 + (13 / 5)) = 6
const b: number = evalRPN(["4", "13", "5", "/", "+"]);

// ((10 * (6 / ((9 + 3) * -11))) + 17) + 5 = 22
const c: number = evalRPN(["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]);

console.log(a + " " + b + " " + c);