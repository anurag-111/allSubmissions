// https://leetcode.com/problems/coin-change

class Solution {
private :
    int dp[10010]; // amount <= 104
    
    int func(vector<int> &coins, int amount) {
        int ans = INT_MAX;
        if(amount == 0) {
            return 0;
        }
        if(dp[amount] != -1) {
            return dp[amount];
        }
        for(int coin : coins) {
            if(amount - coin >= 0) {
                ans = min(ans + 0LL, func(coins, amount - coin) + 1LL);
            }
        }
        return dp[amount] = ans;
    }


public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans = func(coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};