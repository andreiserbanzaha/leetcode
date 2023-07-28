function dailyTemperatures(temperatures: number[]): number[] {

    let answer: number[] = [];
    for (let i: number = 0; i < temperatures.length; ++i) {
        answer.push(0);
    }

    interface Pair {
        temp: number,
        index: number
    }
    let stack: Pair[] = [];

    for (let i: number = 0; i < temperatures.length; ++i) {
        while (stack.length > 0 && temperatures[i] > stack[stack.length - 1].temp) {
            answer[stack[stack.length - 1].index] = i - stack[stack.length - 1].index;
            stack.pop();
        }
        stack.push({ temp: temperatures[i], index: i });
    }

    return answer;
};

{
    const a = dailyTemperatures([73, 74, 75, 71, 69, 72, 76, 73]);
    const b = 0;
}