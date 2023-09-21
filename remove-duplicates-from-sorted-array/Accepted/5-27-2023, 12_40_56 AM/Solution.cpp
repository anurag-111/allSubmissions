// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int countDuplicates = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                countDuplicates++;
            } else {
                // If they are not equal, it means a new element is encountered. 
                // Shift the current element nums[i] to the left by countDuplicates 
                // positions, effectively removing the duplicates before it.
                nums[i - countDuplicates] = nums[i];
            }
        }
        //Return the number of unique elements in the vector.
        return (nums.size() - countDuplicates);
    }
};
