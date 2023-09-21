// https://leetcode.com/problems/n-queens

// https://leetcode.com/problems/n-queens

class Solution {
    public List<List<String>> solveNQueens(int n) {
        
        char[][] board = new char[n][n];
        
        for (int i = 0; i < n; i++) {
            Arrays.fill(board[i], '.');
        }
        List<List<String>> result = new ArrayList<>();
        solve(0, n, board, result);
        return result;
    }
    
    private void solve(int row, int n, char[][] board, List<List<String>> result) {
        if (row == n) {
            constructResult(board, result);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            
            if (isValid(row, col, n, board)) {
                board[row][col] = 'Q';
                solve(row + 1, n, board, result);
                board[row][col] = '.';
            }
        }
    }
    
    private boolean isValid(int row, int col, int n, char[][] board) {
        
        // 1. we always place queen in a new row, so need not check for attacking queens in other rows
        
        // 2. Check if there are other attacking queens in the column = col
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        
        // 3. check if the diag from left to right has attacking queens. 
        // Need to check only for the diagonals above, as the remaining rows have not yet been filled.
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        // 4. Similarly, check for diagonal from right to left
        
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        return true;
    }
    
    private void constructResult(char[][] board, List<List<String>> result) {
        
        List<String> chess = new ArrayList<>();
        for (int i = 0; i < board.length; i++) {
            chess.add(String.valueOf(board[i]));
        }
        result.add(chess);
    }
}