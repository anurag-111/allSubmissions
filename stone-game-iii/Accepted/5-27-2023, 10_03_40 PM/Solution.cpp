// https://leetcode.com/problems/stone-game-iii

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> suffixSum(n+1, 0); // Stores the suffix sum of stone values
        vector<int> dp(n+1, 0); // Stores the maximum score difference for each position

        // Calculate suffix sum
        for (int i = n - 1; i >= 0; i--)
            suffixSum[i] = suffixSum[i + 1] + stoneValue[i];

        // Calculate maximum score difference using dynamic programming
        for (int i = n-1; i >= 0; i--) {
            dp[i] = stoneValue[i] + suffixSum[i+1] - dp[i+1]; // Option 1: Take the current stone and subtract the opponent's best score

            // Check options 2 and 3: Take 2 or 3 stones and subtract the opponent's best score
            for (int k = i+1; k < i+3 && k < n; k++) {
                dp[i] = max(dp[i], suffixSum[i] - dp[k+1]);
            }
        }

        // Compare the scores and determine the winner
        if (dp[0]*2 == suffixSum[0])
            return "Tie";
        else if (dp[0]*2 > suffixSum[0])
            return "Alice";
        else
            return "Bob";
    }
};
