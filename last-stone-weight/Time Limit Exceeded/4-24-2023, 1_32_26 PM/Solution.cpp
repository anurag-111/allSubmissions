// https://leetcode.com/problems/last-stone-weight

class Solution {
    public : 
        int lastStoneWeight(vector<int>& stones) {
            priority_queue<int> weights;
            for (int weight : stones) {
                weights.push(weight);
            }
            while(!weights.empty()) {
                cout<<weights.top();
            }
            return 0;
        }
};