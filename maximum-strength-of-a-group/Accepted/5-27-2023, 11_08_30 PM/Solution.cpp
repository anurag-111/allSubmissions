// https://leetcode.com/problems/maximum-strength-of-a-group

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        //int mask = 1;
        int N = nums.size();
        long result = INT_MIN;
        for(int mask = 1; mask < (1 << N); mask++) {
            long prod = 1;
            for(int i = 0; i < N; i++) {
                if((mask & (1 << i)) > 0) {
                    prod *= nums[i];
                }
            }
            result = max(result, prod);
        }
        return result;
    }
};