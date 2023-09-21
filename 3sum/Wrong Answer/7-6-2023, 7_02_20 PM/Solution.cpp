// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> threeSum;

        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if(sum < 0) {
                    left++;
                    continue;
                } 
                
                if(sum > 0) {
                    right--;
                    continue;
                }
                
                
                vector<int> temp = {nums[left], nums[right], nums[i]};
                threeSum.push_back(temp);
                left++;
                right--;

                while(left < right && nums[left + 1] == nums[left]) {
                    left++;
                }
                
            }    
        }
        return threeSum;
    }
};