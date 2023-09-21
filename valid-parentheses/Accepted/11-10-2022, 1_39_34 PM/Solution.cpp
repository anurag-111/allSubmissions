// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(auto i : s) {
            if(i == '(' || i == '{' || i == '[') {
                st.push(i);
            } 
            else{
                    if(st.empty() || (st.top() == '(' && i != ')') || (st.top() == '{' && i != '}') || st.top() == '[' && i != ']') {
                    return false;
                    }
                st.pop(); //else pop from stack           
            }
        }
        return st.empty();
    }
};
