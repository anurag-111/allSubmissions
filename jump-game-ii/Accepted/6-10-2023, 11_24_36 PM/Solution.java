// https://leetcode.com/problems/jump-game-ii

class Solution {
    public int jump(int[] nums) {
        int currentReach = 0; // Current maximum index reachable with the current number of jumps
        int maxReach = 0; // Maximum index reachable overall
        int jumps = 0; // Number of jumps taken

        for (int i = 0; i < nums.length - 1; i++) { 
            // Update the maximum index reachable with the current number of jumps
            currentReach = Math.max(currentReach, i + nums[i]); 

            if (i == maxReach) { // If we have reached the maximum index reachable so far
                maxReach = currentReach; // Update the maximum index reachable overall
                jumps++;
            }
        }

        return jumps; // Return the minimum number of jumps required to reach the last index
    }
}
