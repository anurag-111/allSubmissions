// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        int reach=0;                                  // reach: maximum reachable index from current position
        int count=0;                                  // count: number of jumps made so far
        int last=0;                                   // last: rightmost index that has been reached so far
        for(int i = 0; i < nums.size() - 1; i++) {    // loop through the array excluding the last element
            reach = max(reach, i + nums[i]);          // update reach to the maximum between reach and i+nums[i]
            if(i == last) {             
                last = reach;                         // update last to the new maximum reachable index
                count++;                              // increment the number of jumps made so far
            }
        }
        return count;                                 // return the minimum number of jumps required
    }
};