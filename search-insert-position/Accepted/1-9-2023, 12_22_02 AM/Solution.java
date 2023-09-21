// https://leetcode.com/problems/search-insert-position

class Solution {
    public int searchInsert(int[] nums, int target) {
        int high = nums.length;
        int low = 0;
        while (low < high) {
            int mid = (low) + (high-low)/2;
            
            if(nums[mid] >= target) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
}