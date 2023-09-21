// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minCur = INT_MAX;
        int maxPro = 0;
        int curPro = 0;

        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < minCur) {
                minCur = prices[i];
            }

            curPro = prices[i] - minCur;

            if(curPro > maxPro) {
                maxPro = curPro;
            }
        }

        return maxPro;
    }
};