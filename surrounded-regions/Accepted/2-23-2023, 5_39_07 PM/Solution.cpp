// https://leetcode.com/problems/surrounded-regions

// class Solution {
// private:
//     int x[4] = {-1, 0, 1, 0};
//     int y[4] = {0, 1, 0, -1};

//     void dfs(int i, int j, vector<vector<char>>& board) {
//         board[i][j] = '#';

//         for(int k = 0; k < 4; k++) {
//             int a = i + x[k];
//             int b = j + y[k];
            
//             if (a >= 0 && a < board.size() && b >= 0 && b < board[0].size() && board[a][b] == 'O') {
//                 dfs(a, b, board);
//             }
//         }

//     }

// public:
//     void solve(vector<vector<char>>& board) {
//         if(board.size() == 0) {
//             return;
//         }

//         for(int i = 0; i < board.size(); i++) {
//             for(int j = 0; j < board[0].size(); j++) {
//                 // Visiting all the boundary conditions
//                 if((i == 0 || j == 0 || i == board.size() - 1 || j == board[0].size() - 1) && (board[i][j] = 'O')) {
//                     dfs(i, j, board);
//                     board[i][j] = '#';    
//                 }
//             }
//         }

//         for(int i =0; i <board.size(); i++){
//            for(int j =0; j <board[0].size(); j++){
//                if(board[i][j] == '#')
//                    board[i][j] = 'O';
//                else if(board[i][j] == 'O')
//                    board[i][j] = 'X';
//            }
//         }
//     }
// };

class Solution {
public:
    int x[4] = {-1,0,1,0};
    int y[4] = {0,1,0,-1};
    void dfs(int i, int j, vector<vector<char>> &board){
        
        board[i][j] = '*';
        
        for(int k = 0; k < 4; k++){
            int a = i + x[k];
            int b = j + y[k];
            
            if(a >= 0 && a < board.size() && b >= 0 && b < board[0].size() && board[a][b] == 'O'){
                dfs(a,b,board);
            }
        }
        
    }
    
    void solve(vector<vector<char>>& board) {
        //int m = board.size();

        if(board.size() == 0) 
            return;

        //int n = board[0].size();
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if((i == 0|| j == 0 || i == board.size() - 1|| j == board[0].size() - 1) and board[i][j] == 'O') {
                    dfs(i, j, board);
                    board[i][j] = '*';
                }
            }
        }
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '*') {
                    board[i][j] = 'O';
                }
                else {
                    board[i][j] = 'X';
                }
                    
            }
        }
    }
};