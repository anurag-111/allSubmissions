// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> ans(len);
        stack<int> st;
        
        for(int i = 0; i <len;i++) {
            while (!st.empty() && (temperatures[st.top()] < temperatures[i])) {
                //found increasing value for st.top() index
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};