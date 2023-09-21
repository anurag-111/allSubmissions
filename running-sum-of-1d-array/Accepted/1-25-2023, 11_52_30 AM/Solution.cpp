// https://leetcode.com/problems/running-sum-of-1d-array

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> sum;
        int cur_sum = 0;
        for (int i : nums) {
            cur_sum += i;
            sum.push_back(cur_sum);
        } 
        return sum;
    }
};