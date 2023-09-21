// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> rowSet[9], colSet[9], boxSet[9];

        // Iterate over each cell in the Sudoku board
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                char cell = board[row][col];

                // Skip empty cells
                if (cell == '.') {
                    continue;
                }

                // Convert the character to a number
                int num = cell - '0';

                // Calculate the box index
                int box = (row / 3) * 3 + (col / 3);

                // Check for redundancy in rows, columns, and boxes
                if (rowSet[row].count(num) || colSet[col].count(num) || boxSet[box].count(num)) {
                    return false; // Invalid Sudoku
                }

                // Insert the number into the corresponding row, column, and box
                rowSet[row].insert(num);
                colSet[col].insert(num);
                boxSet[box].insert(num);
            }
        }

        return true; // Valid Sudoku
    }
};
