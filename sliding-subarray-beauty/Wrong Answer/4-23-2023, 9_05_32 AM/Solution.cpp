// https://leetcode.com/problems/sliding-subarray-beauty

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
    int n = nums.size();
    vector<int> beauty;
    int numNegatives = 0; // Number of negative integers in the current subarray
    priority_queue<int> maxHeap; // Max heap to keep track of the k largest negative integers
    
    for (int i = 0; i < n; i++) {
        if (i >= k) {
            // Remove the element that goes out of the sliding window
            int prev = nums[i - k];
            if (prev <= 0) {
                numNegatives--;
                maxHeap.push(prev);
            }
        }
        // Add the new element in the sliding window
        if (nums[i] <= 0) {
            numNegatives++;
            maxHeap.push(nums[i]);
        }
        
        if (i >= k - 1) {
            // Get the beauty of the subarray
            if (numNegatives >= x) {
                // If there are at least x negative integers, take the xth smallest negative integer
                while (maxHeap.size() > k - x) {
                    maxHeap.pop();
                }
                beauty.push_back(maxHeap.top());
            } else {
                // If there are less than x negative integers, the beauty is 0
                beauty.push_back(0);
            }
        }
    }
    return beauty;
}

};

