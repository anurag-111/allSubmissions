// https://leetcode.com/problems/merge-triplets-to-form-target-triplet

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> result(3, -1);
        for(int i = 0; i < triplets.size(); i++) {
            if(target[0] >= triplets[i][0] && target[1] >= triplets[i][1] && target[2] >= triplets[i][2]) {
                result[0] = max(target[0], triplets[i][0]);
                result[1] = max(target[1], triplets[i][1]);
                result[2] = max(target[2], triplets[i][2]);
            }
        }
        return (result[0] == target[0] && result[1] == target[1] && result[2] == target[2]);
    }
};