// https://leetcode.com/problems/baseball-game

class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        stack<int> stk;
        
        for(string op : ops){
            if(op == "+"){
                int top = stk.top();
                stk.pop();
                int newTop = top + stk.top();
                stk.push(top);
                stk.push(newTop);
            } else if(op == "C") {
                stk.pop();
            } else if(op == "D") {
                stk.push(2 * stk.top());
            } else {
                stk.push(stoi(op));
            }
        }
        
        int result = 0;
        
        while(!stk.empty()){
            result += stk.top();
            stk.pop();
        }
        
        return result;
    }
};