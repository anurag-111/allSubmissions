// https://leetcode.com/problems/coin-change

class Solution {
private:
    static const int MAX_AMOUNT = 10010; // Maximum amount allowed
    int dp[MAX_AMOUNT]; // Amount <= 104

    int calculateMinCoins(vector<int>& coins, int amount) {
        // Check if the amount is already 0
        if (amount == 0) {
            return 0;
        }

        // Check if the result for the current amount has already been calculated
        if (dp[amount] != -1) {
            return dp[amount];
        }

        int ans = INT_MAX;
        // Iterate through all the available coin denominations
        for (int coin : coins) {
            if (amount - coin >= 0) {
                ans = min(ans + 0LL, calculateMinCoins(coins, amount - coin) + 1LL);
            }
        }

        // Store the calculated result for future use
        dp[amount] = ans;
        return ans;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp)); // Initialize dp array with -1
        int minCoins = calculateMinCoins(coins, amount);
        return (minCoins == INT_MAX) ? -1 : minCoins;
    }
};
