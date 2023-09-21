// https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        sort(nums.begin(), nums.end());
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] > mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } 
        return left;          
    }
};