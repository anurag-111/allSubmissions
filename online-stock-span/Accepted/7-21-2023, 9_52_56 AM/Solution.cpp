// https://leetcode.com/problems/online-stock-span

#include <stack>

class StockSpanner {
public:
    // Using a stack to keep track of the stock prices and their spans (number of consecutive days with prices less than or equal to the current day).
    stack<pair<int, int>> stockStack;

    StockSpanner() {
        // Constructor to initialize the stockStack when a new object of StockSpanner is created.
    }

    
    int next(int price) {
        int span = 1; // Initialize the span to 1 for the current stock price.

        // Calculate the span for the current stock price by checking the previous stock prices in the stack.
        while (!stockStack.empty() && stockStack.top().first <= price) {
            span += stockStack.top().second; // Add the span of the previous stock to the current span.
            stockStack.pop(); // Remove the previous stock from the stack since its span has been considered.
        }

        // Add the current stock price and its span to the stack for future calculations.
        stockStack.push({price, span});

        return span; 
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */