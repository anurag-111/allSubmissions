// https://leetcode.com/problems/sum-in-a-matrix

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int matrixSum = 0, colMax;
        
        for(auto &num : nums) {
            sort(num.begin(), num.end());
        }
        
        for(int i = 0; i < nums[0].size(); i++) {
            colMax = 0;
            for(int j = 0; j < nums.size(); j++) {
                colMax = max(colMax, nums[j][i]);
            }
            matrixSum += colMax;
            //cout << colMax << " + ";
        }
        
        return matrixSum;
    }
};