#include <vector>
#include <unordered_set>
#include <cstdint>
#include <utility>
#include <string>

class Solution
{
public:
    bool isValidSudoku(std::vector<std::vector<char>> &board)
    {
        std::unordered_set<std::string> set;

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                char c = board[i][j];
                if (c == '.')
                {
                    continue;
                }

                if (const auto [_, inRow] = set.emplace(std::string{c} + std::string{"in row"} + std::to_string(i));
                    inRow == false)
                {
                    return false;
                }

                if (const auto [_, inCol] = set.emplace(std::string{c} + std::string{"in col"} + std::to_string(j));
                    inCol == false)
                {
                    return false;
                }

                if (const auto [_, inBox] = set.emplace(std::string{c} + std::string{"in box"} + std::to_string(i / 3) + std::to_string(j / 3));
                    inBox == false)
                {
                    return false;
                }
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