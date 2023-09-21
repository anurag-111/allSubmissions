// https://leetcode.com/problems/remove-k-digits

class Solution {
    public :
        string removeKdigits(string num, int k) {
            stack<char> numStack;
            string result = "";
            int size = num.length();

            if(k >= size) {
                return "0";
            }

            for(int i = 0; i < size; i++) {
                while((!numStack.empty()) && (numStack.top() > num[i]) && (k > 0)) {
                    numStack.pop();
                    k--;
                }
                
                if(!numStack.empty() || num[i] != '0') {
                    numStack.push(num[i]);
                }
            }

            while(!numStack.empty() && k > 0) {
                numStack.pop();
                k--;
            }

            while(!numStack.empty()) {
                result += numStack.top();
                numStack.pop();
            }

            reverse(result.begin(), result.end());

            if(result.empty()) {
                return "0";
            } 

            return result;
        }
};