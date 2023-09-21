// https://leetcode.com/problems/number-of-zero-filled-subarrays



class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        long long count = 0; // count of consecutive zeros

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count++;
            } else {
                ans += (count * (count + 1) / 2);
                count = 0; // reset count
            }
        }

        // For cases such as : nums = [0,0,0,2,0,0]
        // The last occurence of 0's subarray count should also be added.
        if(count) {
            ans += (count * (count + 1) / 2);
        }

        return ans;
    }
};

