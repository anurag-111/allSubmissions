// https://leetcode.com/problems/trapping-rain-water

// The problem can be solved using a single traversal, essentially reducing the time complexity to O(N).

// The idea is to consider two arrays left_max[] and right_max[], where left_max[i] will store the maximum height on the left until index i. Similarly,  right_max[i] will store the maximum height on the right until index i.

// Time Complexity: O(N) + O(N) + O(N) = O(N), since the array is traversed thrice.
// Space Complexity: O(N), since two arrays are needed.


class Solution {
public:
    int trap(vector<int>& height) {
        
        int result = 0;
        int size = height.size();
        int left_max[size], right_max[size];
        int max_value = 0;
        
        for(int i = 0;i < size; i++) {
            max_value = max (max_value, height[i]);
            left_max[i] = max_value;
        }
        
        max_value = 0;
        for(int i = size - 1; i >= 0; i--) {
            max_value = max (max_value, height[i]);
            right_max[i] = max_value;
        }
        
        for (int i = 0; i < size; i++) {
            result += min(left_max[i], right_max[i]) - height[i];
        }
        return result;
    }
};