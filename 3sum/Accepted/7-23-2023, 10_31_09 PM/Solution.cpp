// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for(int i = 0; i < nums.size() - 2; i++) {
             
             if (i > 0 && nums[i] == nums[i - 1]) {
                 continue;
             }
             
             int left = i + 1;
             int right = nums.size() - 1;
             int target = (-1) * nums[i];
             
             while(left < right) {
                 int sum = nums[left] + nums[right];

                 if(sum < target) {
                     left++;
                 } else if(sum > target) {
                     right--;
                 } else {
                     result.push_back({nums[i], nums[left], nums[right]});

                     // handling duplicates of the second triplet
                     while(left < right && nums[left] == nums[left + 1]) {
                         left++;
                     }
                     
                     // handling duplicates of the third triplet
                     while(left < right && nums[right] == nums[right - 1]) {
                         right--;
                     }

                     left++;
                     right--;
                 }
             }
        }

        return result;
                                                                  
    }
};