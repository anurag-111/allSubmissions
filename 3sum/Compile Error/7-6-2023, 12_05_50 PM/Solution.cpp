// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<int> uniqueSet;

        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                for(int k= j + 1; j < nums.size(); k++) {
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> foundElements;
                        foundElements.push_back(nums[i]);
                        foundElements.push_back(nums[i]);
                    }
                }
            }
        }
    }
};