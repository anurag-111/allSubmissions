// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> curr;
        vector<vector<int>> result;
        
        subsets_util(nums, 0, curr, result);
        return result;
    }
private:
    void subsets_util(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& result) {
        result.push_back(curr);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) {   // for duplicates
                continue;
            }
            curr.push_back(nums[i]);
            subsets_util(nums, i + 1, curr, result);
            curr.pop_back();
        }
    }
};

// Logic : https://rb.gy/ubsxwf
// Time Complexity : O(n x 2^n)
// Space Complexity : O(n)