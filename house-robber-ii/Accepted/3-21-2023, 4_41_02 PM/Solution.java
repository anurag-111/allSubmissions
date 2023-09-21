// https://leetcode.com/problems/house-robber-ii

class Solution {
    public int rob(int[] nums) {
        if(nums == null || nums.length == 0) {
            return 0;
        }
        int n = nums.length;
        if(n == 1) {
            return nums[0];
        }
        return Math.max(houserob(nums, 0, n - 2), houserob(nums, 1, n - 1));
    }

    private int houserob(int[] nums, int start, int end) {
        if(start > end) {
            return  0;
        } 
        int prev = 0, curr = 0;
        for(int i = start; i <= end; i++) {
            int value = Math.max(prev + nums[i], curr);
            prev = curr;
            curr = value;
        }
        return curr;
    }
}