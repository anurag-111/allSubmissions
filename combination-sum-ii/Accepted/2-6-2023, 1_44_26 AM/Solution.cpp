// https://leetcode.com/problems/combination-sum-ii

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {

        vector<vector<int>> result;
        vector<int> combination;

        sort(candidates.begin(), candidates.end());
        helper(candidates, target, result, combination, 0);

        return result;
    }

    void helper(vector<int> &candidates, int target, vector<vector<int>> &result, vector<int> &combination, int index) {

        if (target == 0) {
            result.push_back(combination);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (target < candidates[i]) {
                return;
            }

            combination.push_back(candidates[i]);
            helper(candidates, target - candidates[i], result, combination, i + 1);
            combination.pop_back();
        }
    }
};

// Time: O(2^n)
// Space: O(n)