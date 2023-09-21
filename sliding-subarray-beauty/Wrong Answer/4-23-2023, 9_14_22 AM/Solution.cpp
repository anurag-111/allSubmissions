// https://leetcode.com/problems/sliding-subarray-beauty

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> result;
        priority_queue<int> pq; // max heap to store negative numbers

        // Process the first k elements
        for (int i = 0; i < k; i++) {
            if (nums[i] < 0) {
                pq.push(nums[i]);
            }
        }

        // Process subarrays of size k and calculate beauty
        for (int i = k; i <= n; i++) {
            int beauty = 0;
            if (!pq.empty()) {
                int size = pq.size();
                if (size >= x) {
                    vector<int> temp;
                    for (int j = 0; j < size; j++) {
                        temp.push_back(pq.top());
                        pq.pop();
                    }
                    beauty = -temp[x - 1];
                    for (int j = 0; j < size; j++) {
                        pq.push(-temp[j]);
                    }
                }
            }
            result.push_back(beauty);

            // Remove element that is no longer part of the subarray
            if (i < n && nums[i - k] < 0) {
                pq.pop();
            }

            // Add next element to the max heap if it is negative
            if (i < n && nums[i] < 0) {
                pq.push(nums[i]);
            }
        }

        return result;
    }


};

