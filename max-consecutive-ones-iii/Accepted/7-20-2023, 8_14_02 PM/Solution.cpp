// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int count = 0;
        int maxCount = 0;
        int size = nums.size();

        while(right < size) {
            if(nums[right] == 0) {
                count++;
            }

            while(count > k) {
                if(nums[left] == 0) {
                    count--;
                }
                left++;
            }

            maxCount = max(maxCount, right - left + 1);
            right++;
        }

        return maxCount;
    }
};