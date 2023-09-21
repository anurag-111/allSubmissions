// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <long> st;
        
        for(auto x : tokens) {
            if(x == "+" || x == "-" || x == "*" || x == "/") {
                long op2 = st.top(); st.pop();
                long op1 = st.top(); st.pop();
                
                if(x == "+") {
                    st.push(op1 + op2);
                }
                else if(x == "-") {
                    st.push(op1 - op2);
                }
                else if(x == "*") {
                    st.push(op1 * op2);
                }
                else if(x == "/") {
                    st.push(op1 / op2);
                }
            } else {
                long num = stoi(x);
                st.push(num);
            }
        }
        return st.top();
    }
};