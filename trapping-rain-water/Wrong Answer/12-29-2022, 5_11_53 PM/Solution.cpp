// https://leetcode.com/problems/trapping-rain-water

// Bruteforce Approach

// Since our task is to find the maximum height on left and right for each element of the array, simply traverse each element of the array A[]. For each element, find the maximum height on the left and maximum height on the right. At last, add min(right_max, left_max) – A[i] to answer.

// Time Complexity: O(N^2). For each element, the left and right half are traversed.
// Space Complexity: O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        for (int i = 1; i < (height.size() - 1); i++) {
            
            //finding left_max
            int left_max = INT_MIN;
            for (int j = i - 1; j >= 0; j--) {
                left_max = max (height[j], left_max);
            }

            //finding right_max
            int right_max = INT_MAX;
            for (int k = i + 1; k < height.size(); k++) {
                right_max = max (height[k], right_max);
            }
            
            //finding the water trapped
            int max_height = min (left_max, right_max);
            result += max_height - height[i];
        }
        return result;
    }
};

