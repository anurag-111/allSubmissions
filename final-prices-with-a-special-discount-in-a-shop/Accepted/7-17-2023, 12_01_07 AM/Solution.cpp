// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        vector<int> discountPrices(prices.size(), 0);
        vector<int> finalPrices(prices.size());

        for(int i = 0; i < prices.size(); i++) {
            while(!st.empty() && prices[st.top()] >= prices[i]) {
                // perform operations
                discountPrices[st.top()] = prices[i];
                st.pop();
            }
            st.push(i);
        }

        for(int i = 0; i < prices.size(); i++) {
            finalPrices[i] = prices[i] - discountPrices[i];
        }

        return finalPrices;      
    }
};


/*

Conditions :
j > i
prices[j] <= prices[i]

Approach :
[8, 4, 6, 2, 3] => nearest smaller elements with conditions (j > i and prices[j] <= prices[i])
                => [4, 2, 2, -1, -1], nearest smaller elements : use stack
                => [4, 2, 4, 2, 3]
*/