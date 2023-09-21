// https://leetcode.com/problems/combination-sum

class Solution {
public:
    
    void helper(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& path, int index) {
        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                return;
            }
            
            path.push_back(candidates[i]);
            helper(candidates, target - candidates[i], result, path, i);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> path;
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, result, path, 0);
        return result;
    }
};

// Time Complexity : O( 2 ^ N)
//Working : https://rb.gy/yquxqm