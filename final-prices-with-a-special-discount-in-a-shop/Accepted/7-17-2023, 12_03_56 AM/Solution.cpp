// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop

class Solution {
public:

    /**
     * @brief Calculates the final prices with discounts.
     * 
     * Given an array of prices, this function calculates the final prices for each element,
     * considering the discount offered.
     * 
     * @param prices The input array containing the original prices.
     * @return A vector containing the final prices after applying the discounts.
     */

    vector<int> finalPrices(vector<int>& prices) {
        stack<int> discountIndices; // Stack to store the indices of elements for which we need to find the discount
        vector<int> discounts(prices.size(), 0); 
        vector<int> finalPrices(prices.size()); 
        
        // Traverse the array to find discounts for each element
        for (int i = 0; i < prices.size(); i++) {
            // While the stack is not empty and the current element's price is less than or equal to the element at the top of the stack
            while (!discountIndices.empty() && prices[discountIndices.top()] >= prices[i]) {
                // Calculate the discount for the element at the top of the stack
                discounts[discountIndices.top()] = prices[i];
                discountIndices.pop();
            }
            // Push the index of the current element onto the stack
            discountIndices.push(i);
        }
        
        // Calculate the final prices after applying the discounts
        for (int i = 0; i < prices.size(); i++) {
            finalPrices[i] = prices[i] - discounts[i];
        }
        
        return finalPrices;
    }
};

// Time Complexity: O(N), where N is the number of elements in the input array.
//                  The algorithm processes each element in the array exactly once.
// Space Complexity: O(N), where N is the number of elements in the input array.
//                   The space is used to store the output array, the stack, and the discounts array,
//                   each of which can have at most N elements.
