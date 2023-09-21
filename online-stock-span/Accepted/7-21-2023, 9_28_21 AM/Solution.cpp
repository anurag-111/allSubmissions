// https://leetcode.com/problems/online-stock-span

class StockSpanner {
public:
    stack<pair<int, int>> st;

    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        
        // continuation of span
        while(!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        // continuation of stocks
        st.push({price, span});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */