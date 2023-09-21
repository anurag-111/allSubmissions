// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n == 0) {
            return 0;
        } 
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for(int gaps = 0; gaps < n; gaps++) {
           for(int i = 0, j = gaps; j < dp.size(); i++, j++) {
                if(gaps == 0) {                                     // For cases with length 1
                    dp[i][j] = 1;
                } else if(gaps == 1) {                              // For cases with length 2
                    dp[i][j] = s[i] == s[j]? 2 : 1;
                } else {
                    if(s[i] == s[j]) {                               // For cases with length >= 3
                        dp[i][j] = 2 + dp[i + 1][j - 1];             // When the extremes are equal
                    } else {
                        dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);  // When the extremes are not equal
                    }
                }
           }
        }
        return dp[0][n - 1];  
    }
    
};