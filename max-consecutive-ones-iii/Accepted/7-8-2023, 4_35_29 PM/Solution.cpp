// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    /**
     * Function to find the length of the longest subarray with at most k zeros
     * @param nums: Input array of integers
     * @param k: Maximum number of zeros allowed
     * @return Length of the longest subarray
     */
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;           // Left pointer for the sliding window
        int zerosCount = 0;     // Count of zeros in the current window
        int right = 0;          // Right pointer for the sliding window
        int longestLength = 0;  // Length of the longest subarray with at most k zeros
        int size = nums.size(); // Size of the input array

        while (right < size) {
            if (nums[right] == 0) {
                zerosCount++;
            }

            // Shrink the window from the left until the zeros count is within the limit
            while (zerosCount > k) {
                if (nums[left] == 0) {
                    zerosCount--;
                }
                left++;
            }

            // Update the longest length if the current window length is greater
            longestLength = max(longestLength, right - left + 1);
            right++;
        }

        return longestLength;
    }
};
