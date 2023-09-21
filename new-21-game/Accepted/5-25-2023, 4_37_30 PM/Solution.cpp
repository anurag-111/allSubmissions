// https://leetcode.com/problems/new-21-game

class Solution {
public:
    double new21Game(int N, int K, int W) {
        // Check if K is 0 or if N is greater than or equal to K + W
        if (K == 0 || N >= K + W) {
            return 1.0;
        }
        
        vector<double> dp(N + 1); // Dynamic programming array
        dp[0] = 1.0; // Initial probability
        
        double sumOfProbabilities = 1.0; // Sum of probabilities
        double result = 0.0; // Final result
        
        for (int i = 1; i <= N; ++i) {
            dp[i] = sumOfProbabilities / W; // Calculate probability for current position
            
            if (i < K) {
                sumOfProbabilities += dp[i]; // Update sum of probabilities
            } else {
                result += dp[i]; // Accumulate result
            }
            
            if (i - W >= 0) {
                sumOfProbabilities -= dp[i - W]; // Remove old probability from sum
            }
        }
        
        return result;
    }

};