// https://leetcode.com/problems/sliding-window-maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        

        for(int i = 0; i < nums.size(); i++) {
            
            // Remove the elements from the window when they exceed
            while(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove the smaller elements
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // Insert the current index
            dq.push_back(i);

            // Insertion of maximum element
            if(i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};