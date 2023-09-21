// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> rows[9], cols[9], boxs[9];
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                char ch = board[i][j];
                if(ch == '.') {
                    continue;
                }

                int num = ch - '0';
                int box = (i / 3) * 3 + (j / 3);

                if(rows[i].count(num) || cols[j].count(num) || boxs[box].count(num)) {
                    return false;
                }

                rows[i].insert(num);
                cols[j].insert(num);
                boxs[box].insert(num);
            }
        }
        return true;
    }
};