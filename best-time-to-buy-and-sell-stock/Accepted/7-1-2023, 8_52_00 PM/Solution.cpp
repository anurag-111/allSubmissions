// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

#include <vector>
#include <climits> // For INT_MAX

class Solution {
public:
    // Function to calculate the maximum profit from buying and selling stocks
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX; // Variable to store the minimum stock price encountered so far
        int maxProfit = 0; // Variable to store the maximum profit achieved so far
        int currentProfit = 0; // Variable to store the current profit

        // Iterate through the stock prices
        for (int i = 0; i < prices.size(); i++) {
            // Update the minimum stock price if a new minimum is found
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }

            // Calculate the current profit by subtracting the minimum price from the current price
            currentProfit = prices[i] - minPrice;

            // Update the maximum profit if a new maximum is found
            if (currentProfit > maxProfit) {
                maxProfit = currentProfit;
            }
        }

        return maxProfit;
    }
};
