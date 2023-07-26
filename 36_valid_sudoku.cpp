#include <vector>
#include <unordered_set>
#include <cstdint>
#include <utility>

class Solution
{
public:
    bool isValidSudoku(std::vector<std::vector<char>> &board)
    {
        // validate lines
        for (const auto &line : board)
        {
            if (!isValid(line))
            {
                return false;
            }
        }

        // validate columns
        for (int col = 0; col < 9; ++col)
        {
            std::vector<char> currCol(9);
            for (int row = 0; row < 9; ++row)
            {
                currCol[row] = board[row][col];
            }

            if (!isValid(currCol))
            {
                return false;
            }
        }

        // validate squares
        std::vector<std::vector<std::vector<char>>> squares(3);
        for (auto &square : squares)
        {
            square.resize(3);
        }

        for (int row = 0; row < 9; ++row)
        {
            for (int col = 0; col < 9; ++col)
            {
                if (board[row][col] == '.')
                {
                    continue;
                }
                squares[row / 3][col / 3].push_back(board[row][col]);
            }
        }

        for (const auto &square : squares)
        {
            for (const auto &v : square)
            {
                if (!isValid(v))
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool isValid(const std::vector<char> &v)
    {
        std::unordered_set<char> set;

        for (char c : v)
        {
            if (c == '.')
            {
                continue;
            }
            const auto [_, inserted] = set.insert(c);
            if (!inserted)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    std::vector<std::vector<char>> board1 = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    std::vector<std::vector<char>> board2 = {
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution s;
    const bool isValidBoard1 = s.isValidSudoku(board1);
    const bool isValidBoard2 = s.isValidSudoku(board2);

    return 0;
}