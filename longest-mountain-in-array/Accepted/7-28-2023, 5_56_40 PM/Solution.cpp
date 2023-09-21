// https://leetcode.com/problems/longest-mountain-in-array

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int maxLen = 0; // Initialize the maximum mountain length to 0
        
        // Iterate through the array, excluding the first and last elements as they can't form a mountain peak
        for (int peak = 1; peak < arr.size() - 1; peak++) {
            // Check if the current element is a peak (larger than its neighbors)
            if (arr[peak] > arr[peak - 1] && arr[peak] > arr[peak + 1]) {
                // Initialize pointers for left and right sides of the mountain
                int left = peak - 1;
                int right = peak + 1;
                
                // Move the left pointer to the left while elements are strictly increasing
                while (left > 0 && arr[left] > arr[left - 1]) {
                    left--;
                }
                
                // Move the right pointer to the right while elements are strictly decreasing
                while (right < arr.size() - 1 && arr[right] > arr[right + 1]) {
                    right++;
                }
                
                // Calculate the length of the mountain and update maxLen if needed
                maxLen = max(maxLen, right - left + 1);
            }
        }
        return maxLen; // Return the maximum mountain length
    }
};
