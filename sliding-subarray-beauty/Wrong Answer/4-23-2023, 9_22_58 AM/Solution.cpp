// https://leetcode.com/problems/sliding-subarray-beauty

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> result;
        priority_queue<int> pq; // Max heap (priority queue) to store negative integers
        int negCount = 0; // Count of negative integers in current subarray

        // Iterate through nums from left to right
        for (int i = 0; i < nums.size(); ++i) {
            // If current element is within first k elements and negative, push onto pq and increment negCount
            if (i < k && nums[i] < 0) {
                pq.push(nums[i]);
                ++negCount;
            }
            // If current element is beyond first k elements
            else if (i >= k) {
                // Check if there are any negative integers in pq, and pop elements until we have found x smallest negative integers
                while (!pq.empty() && negCount > x) {
                    pq.pop();
                    --negCount;
                }

                // Calculate beauty of subarray based on remaining count of negative integers in pq
                if (!pq.empty()) {
                    // If there are remaining negative integers in pq, push top element (maximum negative integer) onto result
                    result.push_back(pq.top());
                }
                else {
                    // Otherwise, push 0 onto result
                    result.push_back(0);
                }

                // Remove element that is no longer part of subarray from pq if it is negative
                if (!pq.empty() && pq.top() == nums[i - k]) {
                    pq.pop();
                    --negCount;
                }

                // Add new element to subarray in pq if it is negative
                if (nums[i] < 0) {
                    pq.push(nums[i]);
                    ++negCount;
                }
            }
        }

        // Process remaining negative integers in pq for last subarray
        while (!pq.empty() && negCount > x) {
            pq.pop();
            --negCount;
        }

        // Calculate beauty of last subarray based on remaining count of negative integers in pq
        if (!pq.empty()) {
            // If there are remaining negative integers in pq, push top element (maximum negative integer) onto result
            result.push_back(pq.top());
        }
        else {
            // Otherwise, push 0 onto result
            result.push_back(0);
        }

        return result;
    }


};

