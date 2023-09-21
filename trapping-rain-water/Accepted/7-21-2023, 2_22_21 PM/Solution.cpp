// https://leetcode.com/problems/trapping-rain-water

class Solution {
    public :
        int trap(vector<int> &height) {
            // Appraoch :
            int size = height.size();
            int leftMax[size];
            int rightMax[size];
            int maxValue = 0;
            int result = 0; // how much water s being trapped 

            // 1. traversal for the max left boundary -> O(N)
            for(int i = 0; i < size; i++) {
                maxValue = max(maxValue, height[i]);
                leftMax[i] = maxValue;
            }


            maxValue= 0; // reset the variable for further usage
            
            // 2. traversal for the max right boundary -> O(N)
            for(int i = size - 1; i >= 0; i--) {
                maxValue = max(maxValue, height[i]);
                rightMax[i] = maxValue;
            }

            // 3. Calculation of area trapped
            for(int i = 0; i < size; i++) {
                result += min(leftMax[i], rightMax[i]) - height[i];
            }

            return result;
        }
};