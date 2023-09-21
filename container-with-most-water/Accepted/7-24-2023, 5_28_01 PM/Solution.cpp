// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        // Initialize left and right pointers to track the two ends of the container.
        int left = 0;
        int right = height.size() - 1;

        // Variable to store the maximum area.
        int maxArea = 0;

        // Loop until the left and right pointers meet.
        while (left < right) {
            // Calculate the current area using the minimum of the two heights multiplied by the width.
            int currArea = min(height[left], height[right]) * (right - left);

            // Update the maximum area if the current area is greater.
            maxArea = max(maxArea, currArea);

            // Move the pointer with the smaller height towards the other end.
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }            
        }
        
        // Return the maximum area found.
        return maxArea;
    }
};
