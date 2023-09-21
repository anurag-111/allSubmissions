// https://leetcode.com/problems/maximum-or

class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        long long prefix[n + 1], suffix[n + 1];
        long long result, power = 1;

        // Calculate the power of 2
        for (int i = 0; i < k; i++) {
            power *= 2;
        }

        prefix[0] = 0;
        // Calculate prefix OR values
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] | nums[i];
        }

        suffix[n] = 0;
        // Calculate suffix OR values
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] | nums[i];
        }

        result = 0;
        // Find the maximum OR value
        for (int i = 0; i < n; i++) {
            result = max(result, prefix[i] | (nums[i] * power) | suffix[i + 1]);
        }

        return result;
    }
};
