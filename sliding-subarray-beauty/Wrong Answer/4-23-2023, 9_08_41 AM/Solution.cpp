// https://leetcode.com/problems/sliding-subarray-beauty

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> result;
        priority_queue<int> pq; // max heap to store negative numbers

        // Process the first k-1 elements
        for (int i = 0; i < k - 1; i++) {
            if (nums[i] < 0) {
                pq.push(nums[i]);
            }
        }

        // Process subarrays of size k and calculate beauty
        for (int i = k - 1; i < n; i++) {
            if (nums[i] < 0) {
                pq.push(nums[i]);
            }

            int beauty = 0;
            if (!pq.empty()) {
                int size = pq.size();
                if (size >= x) {
                    for (int j = 1; j <= x; j++) {
                        beauty = pq.top();
                        pq.pop();
                    }
                }
            }
            result.push_back(beauty);

            // Remove element that is no longer part of the subarray
            if (nums[i - k + 1] < 0) {
                pq.pop();
            }
        }

        return result;
    }
};

