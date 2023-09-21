// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
         int maxArea = INT_MIN;
         for(int i = 0; i < height.size(); i++) {
             int left = i;
             int right =  i + 1;
             int area = 0;

             while(right < height.size()) {
                 area = min(height[left], height[right]) * (right - left);
                 maxArea = max(area, maxArea);
                 right++; 
             }
         }

         return maxArea;
    }
};