// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        
        if(nums.size() < 3) {
            return nums.size();
        }

        for(auto &num : nums) {
            if(count < 2 || num > nums[count - 2]) {
                nums[count++] = num;
            }
        }

        return count;
    }
};