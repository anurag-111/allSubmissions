// https://leetcode.com/problems/make-array-empty

class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        
        if(is_sorted(nums.begin(), nums.end())) {
            return nums.size();
        }
        
        deque<int> dq(nums.begin(), nums.end()); 
        priority_queue<int, vector<int>, greater<int>> min_heap(nums.begin(), nums.end());
        
        
        long long count = 0;
        while(!dq.empty() || !min_heap.empty()) {
            if(dq.front() == min_heap.top()) {
                dq.pop_front();
                min_heap.pop();
                count++;
            } else {
                int front_val = dq.front();
                dq.pop_front();
                dq.push_back(front_val);
                count++;
            }
        }
        return count;
    }
};