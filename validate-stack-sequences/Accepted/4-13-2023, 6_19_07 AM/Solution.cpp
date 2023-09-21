// https://leetcode.com/problems/validate-stack-sequences

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack <int> stk;
        int j = 0;
        for(int itr : pushed) {
            stk.push(itr);
            while(!stk.empty() && j < popped.size() && stk.top() == popped[j]) {
                stk.pop();
                j++;
            }
        }
        return stk.empty();
    }
};