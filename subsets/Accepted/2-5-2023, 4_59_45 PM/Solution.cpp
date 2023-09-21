// https://leetcode.com/problems/subsets

class Solution {
private: 
    vector<vector<int>> allSubsets;

    void generate(vector<int> &subset, int i, vector<int> &nums) {
        if (i == nums.size()) {
            allSubsets.push_back(subset);
            return;
        }

        // ith element not in subset
        generate(subset, i + 1, nums);

        // ith element to be in subset
        subset.push_back(nums[i]);
        generate(subset, i + 1, nums);
        subset.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> empty; // for the working subset
        generate(empty, 0, nums);
        return allSubsets;
    }
};

// Time Complexity : 2 ^ N
// Working : https://rb.gy/lyjfag 
