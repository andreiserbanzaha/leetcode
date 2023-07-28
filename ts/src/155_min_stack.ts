class MinStack {
    constructor() {

    }

    push(val: number): void {
        this.stack.push(val);

        if (this.stack.length == 1) {
            this.mins.push(val);
            return;
        }

        const currMin: number = this.mins[this.mins.length - 1];
        if (currMin > val) {
            this.mins.push(val);
        }
        else {
            this.mins.push(currMin);
        }

    }

    pop(): void {
        this.stack.pop();
        this.mins.pop();
    }

    top(): number {
        return this.stack[this.stack.length - 1];
    }

    getMin(): number {
        return this.mins[this.mins.length - 1];
    }

    stack: number[] = [];
    mins: number[] = [];
}

{
    let minStack: MinStack = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin(); // return -2
}