// https://leetcode.com/problems/word-search

class Solution {
public :
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(adjacentSearch(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private :
    bool adjacentSearch(vector<vector<char>>& board, const string& word, int i, int j, int index)
    {
        if(index == word.size()) {
            return true;
        } 

        if(i < 0 || j < 0 || i > board.size() - 1 || j > board[0].size() - 1) {
            return false;
        }

        if(board[i][j] != word[index]) {
            return false;
        }
       
        board[i][j] = '*'; // to avoid duplicated search
        bool furtherSearch =  adjacentSearch(board, word, i+1, j, index+1) || // up
                              adjacentSearch(board, word, i-1, j, index+1) || // down
                              adjacentSearch(board, word, i, j-1, index+1) || // left
                              adjacentSearch(board, word, i, j+1, index+1);   // right
        
        board[i][j] = word[index]; // modify it back.
        return furtherSearch;
    }
};

// Time Complexity: O(mn)
// Space Complexity:O((word_length)^2)