// https://leetcode.com/problems/max-consecutive-ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curCount = 0;
        int maxCount = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                curCount++;
            } else {
                curCount = 0;
            }
            maxCount = max(maxCount, curCount);
        }
        return maxCount;
    }
};