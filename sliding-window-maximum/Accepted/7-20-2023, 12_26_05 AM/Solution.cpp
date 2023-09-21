// https://leetcode.com/problems/sliding-window-maximum

#include <vector>
#include <deque>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> windowIndices; // Store indices of elements in the current window
        vector<int> result; // Store the maximum values for each valid window
        
        for (int i = 0; i < nums.size(); i++) {
            // Remove all elements out of range from the window
            while (!windowIndices.empty() && windowIndices.front() <= i - k) {
                windowIndices.pop_front();
            }           
            
            // Remove elements smaller than nums[i] from the back of the deque
            while (!windowIndices.empty() && nums[windowIndices.back()] <= nums[i]) {
                windowIndices.pop_back();
            }
            
            // Add current index to the window
            windowIndices.push_back(i);
            
            // If we have a valid window, update the result with the maximum value
            if (i >= k - 1) {
                result.push_back(nums[windowIndices.front()]);
            }
        }
         
        return result;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(k)
