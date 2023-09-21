// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array

class Solution {
public:
    // Function to find the minimum pair sum in the given vector.
    int minPairSum(vector<int>& nums) {
        // Initialize pointers for left and right ends of the sorted vector.
        int left = 0;
        int right = nums.size() - 1;
        
        // Variable to store the maximum pair sum found so far.
        int maxPairSum = INT_MIN;
        
        // Sort the input vector in ascending order.
        sort(nums.begin(), nums.end());
        
        // Loop until the left pointer crosses the right pointer.
        while (left < right) {
            // Calculate the current pair sum.
            int currentPairSum = nums[left] + nums[right];
            
            // Update the maximum pair sum if the current sum is greater.
            maxPairSum = max(maxPairSum, currentPairSum);
            
            // Move the pointers inward to consider the next pair.
            left++;
            right--;
        }
        
        // Return the maximum pair sum found.
        return maxPairSum;
    }
};
