// https://leetcode.com/problems/coin-change

// Recursion : TLE

class Solution {
private :
    int func(vector<int> &coins, int amount) {
        int ans = INT_MAX;
        if(amount == 0) {
            return 0;
        }
        for(int coin : coins) {
            if(amount - coin >= 0) {
                ans = min(ans + 0LL, func(coins, amount - coin) + 1LL);
            }
        }
        return ans;
    }


public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = func(coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};