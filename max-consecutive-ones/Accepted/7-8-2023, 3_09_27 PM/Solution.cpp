// https://leetcode.com/problems/max-consecutive-ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currentCount = 0; // Count of consecutive ones in the current sequence
        int maxCount = 0; // Maximum count of consecutive ones

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                currentCount++;
            } else {
                currentCount = 0;
            }

            maxCount = max(maxCount, currentCount);
        }

        return maxCount;
    }
};
