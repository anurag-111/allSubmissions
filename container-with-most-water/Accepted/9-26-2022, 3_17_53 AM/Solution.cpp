// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maximum = 0;
        while(left < right){
            //int w = right - left;
            //int h = min(height[left], height[right]);
            int area = (right - left) * (min(height[left], height[right]));
            maximum = max(maximum, area);
            if(height[left] < height[right]) 
                left++;
            else if(height[left] > height[right]) 
                right--;
            else {
                left++;
                right--;
            }
        }
        return maximum;
    }
};