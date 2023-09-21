// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    // Function to calculate the maximum profit
    int maxProfit(vector<int>& prices) {
        // Initialize variables
        int maxProfit = 0;                          // Maximum profit achieved
        int currentProfit = 0;                      // Current profit at each iteration
        int minPrice = INT_MAX;                     // Minimum price encountered
        
        // Iterate through the prices
        for (int i = 0; i < prices.size(); i++) {
            // Update the minimum price encountered so far
            minPrice = min(minPrice, prices[i]);
            
            // Calculate the profit by subtracting the minimum price from the current price
            currentProfit = prices[i] - minPrice;
            
            // Update the maximum profit if the current profit is higher
            maxProfit = max(maxProfit, currentProfit);
        }
        
        // Return the maximum profit
        return maxProfit;
    }
};

/*

Time Complexity (TC): O(n)

Space Complexity (SC): O(1)


*/