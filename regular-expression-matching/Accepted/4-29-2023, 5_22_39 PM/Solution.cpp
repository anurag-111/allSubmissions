// https://leetcode.com/problems/regular-expression-matching

class Solution {
public:
    bool isMatch(string s, string p) {
        
        // Create a 2D boolean vector with p.size() + 1 rows and s.size() + 1 columns,
        // and initialize all elements to false.
        vector<vector<bool>> dp(p.size() + 1, vector<bool> (s.size() + 1, false));
        
        // Loop through all elements of the dp vector.
        for(int i = 0; i < dp.size(); i++) {
            for(int j = 0; j < dp[0].size(); j++) {
                
                // This condition checks if both the string and pattern are empty, 
                // which means they match by default, so dp[i][j] is set to true.
                if(i == 0 && j == 0) {
                    dp[i][j] = true;
                } 
                
                // This condition checks if the pattern is empty but the string is not. 
                // In this case, there cannot be a match between the string and pattern, 
                // so dp[i][j] is set to false.
                else if(i == 0) {
                    dp[i][j] = false;
                } 
                
                // This condition checks if the string is empty but the pattern is not.  
                else if(j == 0) {
                    // In this case, the only way there can be a match is if the pattern 
                    // consists entirely of * characters, which can match an empty string. 
                    // The code checks the character immediately before the * in the pattern (i.e., p[i - 1]).
                    char patternCharacter = p[i - 1];
                    
                    // If the character is '*', set dp[i][j] to the value of dp[i-2][j].
                    // i.e., sets dp[i][j] based on whether the pattern before that (i.e., p[i - 2]) 
                    // can match an empty string.
                    if(patternCharacter == '*') {
                        dp[i][j] = dp[i - 2][j];
                    } 
                    
                    // Otherwise, set dp[i][j] to false.
                    else {
                        dp[i][j] = false;
                    }
                } 
                
                // This condition covers the main logic of the algorithm. 
                // It checks the current character in both the string (s[i-1]) 
                // and pattern (p[i-1]) and sets dp[i][j] based on whether there is a match.
                else {
                    char patternCharacter = p[i - 1];
                    char stringCharacter = s[j - 1];                      
                    if(patternCharacter == '*') {
                        // If the pattern character is *, then there are two possibilities: 
                        // either the * matches zero occurrences of the preceding character, 
                        // in which case dp[i][j] is set to dp[i-2][j].
                        dp[i][j] = dp[i - 2][j];
                        
                        // OR

                        // The * matches one or more occurrences of the preceding character, 
                        // in which case dp[i][j] is set to dp[i][j-1] or dp[i-1][j-1] 
                        // depending on whether the preceding character matches the current character in the string.
                        char patternSecondLastCharacter = p[i - 2];
                        if(patternSecondLastCharacter == '.' || patternSecondLastCharacter == stringCharacter) {
                            dp[i][j] = dp[i][j - 1] || dp[i][j];
                        }     
                    } 
                    
                    // If the pattern character is ., then it matches any character in the string, 
                    // so dp[i][j] is set to dp[i-1][j-1]..
                    else if(patternCharacter == '.'){
                        dp[i][j] = dp[i - 1][j - 1];
                    } 
                    
                    // If the pattern character is not * or ., then it must match the 
                    // corresponding character in the string for there to be a match, 
                    // so dp[i][j] is set to dp[i-1][j-1] if the characters.
                    else if(patternCharacter == stringCharacter) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } 
                    
                    // If none of the above conditions are met, set dp[i][j] to false.
                    else {
                        dp[i][j] = false;
                    }

                }
            }
        }
        
        // Return the value of dp[p.size][s.size]
        return dp[p.size()][s.size()];
    }
};