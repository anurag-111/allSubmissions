// https://leetcode.com/problems/minimum-moves-to-equal-array-elements

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int minVal = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            minVal = min(minVal, nums[i]);
        }
        return sum - (minVal * nums.size());
    }
};

    // Explanation of sum - (minVal * nums.size());
    
    // In each move, we increment all but one element by 1.
    // By incrementing all elements except the minimum one, we effectively reduce the difference between the elements.
    // The minimum number of moves needed to make all elements equal is equal to the sum of differences between each 
    // element and the minimum element.
    
    // (minNum * nums.size()) represents the sum of the minimum element repeated nums.size() times 
    // (as we need to subtract this amount to equalize the elements).
    
    // Thus, subtracting (minNum * nums.size()) from totalSum gives us the minimum number of moves required.
