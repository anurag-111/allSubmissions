// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    int left = 0 , right = int(nums.size()) - 1 , tempSum;
    while(left < right)
    {
        tempSum = nums[left] + nums[right];
        if(tempSum == target)
            return {left,right};
        if(tempSum > target)
            right--;
        else
            left++;
    }
    return {-1 , -1};
    }
};