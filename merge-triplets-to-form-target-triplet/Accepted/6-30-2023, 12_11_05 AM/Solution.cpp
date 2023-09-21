// https://leetcode.com/problems/merge-triplets-to-form-target-triplet

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> result(3, 0);
        for(int i = 0; i < triplets.size(); i++) {
            if(target[0] >= triplets[i][0] && target[1] >= triplets[i][1] && target[2] >= triplets[i][2]) {
                result[0] = max(result[0], triplets[i][0]);
                result[1] = max(result[1], triplets[i][1]);
                result[2] = max(result[2], triplets[i][2]);
            }
        }
        return (result == target);
    }
};