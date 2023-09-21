// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int zeroCount = 0;
        int longestOne = 0;
        
        while(right < nums.size()) {
            if(nums[right] == 0) {
                zeroCount++;
            }
            
            while(zeroCount > k) {
                if(nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            
            longestOne = max(longestOne, (right - left + 1));
            right++;
        }
        
        return longestOne;
    }
};