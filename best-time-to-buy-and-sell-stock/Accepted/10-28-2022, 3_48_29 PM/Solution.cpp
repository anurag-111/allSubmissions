// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_value = INT_MAX;
        int max_profit = 0;
        int cur_profit = 0;
        
        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < min_value) {
                min_value = prices[i];
            }
            cur_profit = prices[i] - min_value;
            if(max_profit < cur_profit) {
                max_profit = cur_profit;
            }
        }
        return max_profit;
    }
};