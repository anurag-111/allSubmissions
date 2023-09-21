// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return dp(s, 0, n - 1, memo);
    }
    
    int dp(string &s, int i, int j, vector<vector<int>>& memo) {
        if (i >= j) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        return memo[i][j] = s[i] == s[j] ? dp(s, i + 1, j - 1, memo) : 1 + min(dp(s, i + 1, j, memo), dp(s, i, j - 1, memo));
    }
};

/*
    The line memo[i][j] = s[i] == s[j] ? dp(s, i + 1, j - 1, memo) : 1 + min(dp(s, i + 1, j, memo), dp(s, i, j - 1, memo)); 
    has the following logic:

        1. If s[i] is equal to s[j], it means the characters at indices i and j are the same, 
           so we can skip them and check the substring s[i+1] to s[j-1]. We recursively call 
           dp(s, i + 1, j - 1, memo) to compute the minimum number of insertions needed for the remaining substring.

        2. If s[i] is not equal to s[j], it means the characters at indices i and j are not the same. 
    
            In this case, we have two options:
    
                A. Insert a character at index i to make it equal to the character at index j, 
                   and recursively call dp(s, i + 1, j, memo) to compute the minimum number of 
                   insertions needed for the remaining substring.

                B. Insert a character at index j to make it equal to the character at index i, 
                   and recursively call dp(s, i, j - 1, memo) to compute the minimum number of 
                   insertions needed for the remaining substring.
*/
