// https://leetcode.com/problems/sliding-subarray-beauty

class Solution {
public:
vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> result;
        vector<int> temp;
        priority_queue<pair<int, int>> pq; // max heap to store negative integers
        int negCount = 0; // count of negative integers in the current subarray
        
        for (int i = 0; i < n; i++) {
            if (i < k) {
                if (nums[i] < 0) {
                    pq.push({-nums[i], i});
                    negCount++;
                }
            } else {
                if (negCount > 0) {
                    while (negCount >= x) {
                        negCount--;
                        temp.push_back(pq.top().first);
                        pq.pop();
                    }
                    if (negCount > 0) {
                        result.push_back(pq.top().first);
                    } else {
                        result.push_back(0);
                    }
                } else {
                    result.push_back(0);
                }
                
                // Remove element that is no longer part of the subarray
                if (nums[i - k] < 0) {
                    negCount--;
                    // Mark the element as removed by setting its index to -1
                    pq.push({-nums[i - k], -1});
                }
                
                // Add new element to the subarray
                if (nums[i] < 0) {
                    pq.push({-nums[i], i});
                    negCount++;
                }
            }
        }
        
        // Process the last subarray after the loop
        if (negCount > 0) {
            while (negCount >= x) {
                negCount--;
                temp.push_back(pq.top().first);
                pq.pop();
            }
            if (negCount > 0) {
                result.push_back(pq.top().first);
            } else {
                result.push_back(0);
            }
        } else {
            result.push_back(0);
        }
        
        return result;
    }


};

