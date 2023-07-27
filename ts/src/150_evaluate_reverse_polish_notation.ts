
function evalRPN(tokens: string[]): number {
    let numbers: number[] = [];
    tokens.forEach(el => {
        switch (el) {
            case "+": {
                const last = numbers.pop();
                if (last !== undefined) {
                    numbers[numbers.length - 1] += last;
                }
                break;
            }
            case "-": {
                const last = numbers.pop();
                if (last !== undefined) {
                    numbers[numbers.length - 1] -= last;
                }
                break;
            }
            case "*": {
                const last = numbers.pop();
                if (last !== undefined) {
                    numbers[numbers.length - 1] *= last;
                }
                break;
            }
            case "/": {
                const last = numbers.pop();
                if (last !== undefined) {
                    numbers[numbers.length - 1] = Math.trunc(numbers[numbers.length - 1] / last);
                }
                break;
            }
            default: {
                numbers.push(+el);
                break;
            }
        }
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