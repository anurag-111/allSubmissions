// https://leetcode.com/problems/last-stone-weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> weights(stones.begin(), stones.end());
        while (weights.size() > 1) {
            int y = weights.top();
            weights.pop();
            int x = weights.top();
            weights.pop();
            if (x != y) {
                weights.push(y - x);
            }
        }
        return weights.empty()? 0 : weights.top();
    }
};