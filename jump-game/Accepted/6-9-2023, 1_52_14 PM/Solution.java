// https://leetcode.com/problems/jump-game

class Solution {
    public boolean canJump(int[] nums) {
        int reachable = 0; // Represents the maximum reachable index from the current position
        
        for (int i = 0; i < nums.length; i++) {
            if (i > reachable) { // If the current index is beyond the maximum reachable index
                return false; // It is not possible to reach the last index
            }
            
            reachable = Math.max(reachable, i + nums[i]); // Update the maximum reachable index
        }
        
        return true; // It is possible to reach the last index
    }
}
