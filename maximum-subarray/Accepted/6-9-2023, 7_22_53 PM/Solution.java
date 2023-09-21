// https://leetcode.com/problems/maximum-subarray

class Solution {
    public int maxSubArray(int[] nums) {
        int currSum = 0; // Current sum of the subarray
        int maxSum = nums[0]; // Maximum sum found so far
        
        for (int num : nums) { // Iterate through the array
            currSum += num; // Add the current number to the current sum
            
            if (currSum > maxSum) { // If the current sum is greater than the max sum
                maxSum = currSum; // Update the max sum
            }
            
            if (currSum < 0) { // If the current sum becomes negative
                currSum = 0; // Reset the current sum to 0
            }
        }
        
        return maxSum; // Return the maximum sum found
    }
}
