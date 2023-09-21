// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = INT_MIN;

        while (left < right) {
            // Calculate the area between the two pointers
            int area = min(height[left], height[right]) * (right - left);

            // Update the maximum area if necessary
            maxArea = max(maxArea, area);

            // Move the pointer with the smaller height inward
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};
