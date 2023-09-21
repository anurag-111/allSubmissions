// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rows(9);
        vector<unordered_set<int>> cols(9);
        vector<unordered_set<int>> blocks(9); 
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    continue;
                }
                
                int current = board[i][j]; 
                if(rows[i].count(current) || cols[j].count(current) ||
                  blocks[(i/3)*3 + j/3].count(current)){
                    return false;
                }
                else{
                rows[i].insert(current);
                cols[j].insert(current);
                blocks[(i/3*3) + j/3].insert(current);
                }
            }
        }
        return true;
    }
};