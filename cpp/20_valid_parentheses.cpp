#include <stack>
#include <string>

class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> stack;
        for (char c : s)
        {
            if (isOpen(c))
            {
                stack.push(c);
                continue;
            }

            if (stack.empty())
            {
                return false;
            }

            char top = stack.top();
            if (!isOpen(top))
            {
                return false;
            }

            if ((top == '(' && c != ')') || (top == '[' && c != ']') || (top == '{' && c != '}'))
            {
                return false;
            }
            stack.pop();
        }

        return stack.empty();
    }

    bool isOpen(char c)
    {
        return c == '(' || c == '[' || c == '{';
    }
};

int main()
{
    Solution s;
    const bool isValidS1 = s.isValid("()");     // true
    const bool isValidS2 = s.isValid("()[]{}"); // true
    const bool isValidS3 = s.isValid("(]");     // false

    return 0;
}