#include <vector>

class MinStack
{
public:
    MinStack()
    {
    }

    void push(int val)
    {
        _data.push_back(val);
        if (val < _min)
        {
            _min = val;
        }
    }

    void pop()
    {
        _data.pop_back();
    }

    int top()
    {
        return _data.back();
    }

    int getMin()
    {
        return _min;
    }

private:
    int _min = 0;
    std::vector<int> _data;
};

int main()
{
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    minStack->getMin(); // return -3
    minStack->pop();
    minStack->top();    // return 0
    minStack->getMin(); // return -2

    return 0;
}