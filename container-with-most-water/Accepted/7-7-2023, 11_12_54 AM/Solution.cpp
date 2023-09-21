// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = INT_MIN;

        while(left < right) {
            int area = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, area);

            if(height[left] > height[right]) {
                right--;
            } else if(height[right] > height[left]) {
                left++;
            } else {
                left++;
                right--;
            }
        }
        return maxArea;
    }
};