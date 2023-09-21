// https://leetcode.com/problems/extra-characters-in-a-string

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict;
        
        // Add dictionary words to a set for faster lookup
        for (const string& word : dictionary) {
            dict.insert(word);
        }
        
        int N = s.length();
        vector<int> dp(N, 0);  // Dynamic programming array to store minimum extra characters
        
        // Check if the first character of the string is in the dictionary
        // If not, we need at least one extra character
        if (dict.find(s.substr(0, 1)) == dict.end()) {
            dp[0] = 1;
        }
        
        for (int i = 1; i < N; i++) {
            dp[i] = dp[i - 1] + 1;  // Assume we need to add one more character
            
            // Check if the substring from the start to the current index is in the dictionary
            // If it is, no extra characters are needed
            if (dict.find(s.substr(0, i + 1)) != dict.end()) {
                dp[i] = 0;
            }
            
            // Try to find a substring from the leftmost character to the current index
            // that is in the dictionary, and update the minimum extra characters needed
            for (int left = 1; left <= i; left++) {
                if (dict.find(s.substr(left, i - left + 1)) != dict.end()) {
                    dp[i] = min(dp[i], dp[left - 1]);
                }
            }
        }
        
        return dp[N - 1];  // Return the minimum extra characters needed
    }
};