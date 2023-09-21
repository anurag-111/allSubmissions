// https://leetcode.com/problems/last-stone-weight

class Solution {
    public : 
        int lastStoneWeight(vector<int>& stones) {
            priority_queue<int> weights;
            for (int weight : stones) {
                weights.push(weight);
            }

            // while(!weights.empty()) {
            //     cout<<weights.top()<<" ";
            //     weights.pop();
            // }

            while(weights.size() > 1) {
                int y = weights.top();  //x <= y
                weights.pop();
                int x = weights.top();
                weights.pop();

                if(x != y) {
                    weights.push(y - x);
                }
            }
            
            return weights.empty() == true ? 0 : weights.top();            
        }
};