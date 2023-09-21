// https://leetcode.com/problems/buy-two-chocolates

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int spent = prices[0] + prices[1];
        if(spent > money) {
            return money;
        }
        return money - spent;
    }
};

/*
    [3,2,3] money = 6
    output : 1
    
    to minimize the sum of the prices of the two chocolates you buy!
    
*/