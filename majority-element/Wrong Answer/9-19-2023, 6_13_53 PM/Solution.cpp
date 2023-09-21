// https://leetcode.com/problems/majority-element

// Boyer-Moore Majority Vote Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = nums[0];
        int count = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(element = nums[i]) {
                count++;                // Same element is found
            } else {
                count--;                // Different element is found
            }
            
            if(count == 0) {            // Count of the current answer is no loger majority
                element = nums[i];
                count = 1;
            }
        }
        return element;
    }
};

// TC : O(N)
// SC : O(1)
