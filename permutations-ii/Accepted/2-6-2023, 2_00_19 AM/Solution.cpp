// https://leetcode.com/problems/permutations-ii

class Solution {
public:
    void permute(vector<vector<int>> &result, vector<int> &permutation, vector<int> &nums, vector<bool> &used) {
      
        if (permutation.size() == nums.size()) {
            result.push_back(permutation);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
                
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
                
            used[i] = true;
            permutation.push_back(nums[i]);
            permute(result, permutation, nums, used);
            permutation.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> result;
        int n = nums.size();
        vector<bool> used(n, false);
        vector<int> permutation;

        if (n == 0) {
            return result;
        }
        
        sort(nums.begin(), nums.end());
        permute(result, permutation, nums, used);
        return result;
    }
};


// if (i > 0 && nums[i] == nums[i - 1] && !use[i - 1]) continue; 

// means, in other words, if previous identical number is used, then use the current number.

// Working : https://ibb.co/Sw0fgk5


//__________________________________________________________________________________________//


// if (i > 0 && nums[i] == nums[i - 1] && use[i - 1]) continue; 

// which means if previous identical number is NOT used, use this number,
// you are going to have to keep running the program until the next identical number 
// first populates the temp/list array before the previous identical number, and then 
// you backtrack into the first identical number which then populates the temp/list array.

// Working : https://ibb.co/n0js4B6