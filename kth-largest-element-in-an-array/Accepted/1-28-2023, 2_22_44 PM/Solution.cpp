// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //create a min heap
        priority_queue<int, vector<int>, greater<int>> pq;

        //iterate over vector nums and push elements into pq
        for (auto itr : nums) {
            pq.push(itr);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};