// https://leetcode.com/problems/find-pivot-index

// Time Complexity : O(n)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        
        for (int idx = 0; idx < nums.size(); idx++) {

            // subtract current elements with from rightSum...
            rightSum -= nums[idx];

            // If the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right...
            if (leftSum == rightSum)
                return idx;     // Return the pivot index...

            // add current elements with leftSum...
            leftSum += nums[idx];
        }

        return -1;      // If there is no index that satisfies the conditions in the problem statement...
    }
};