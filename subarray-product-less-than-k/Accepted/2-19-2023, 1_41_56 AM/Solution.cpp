// https://leetcode.com/problems/subarray-product-less-than-k

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) {
            return 0;
        }

        int count = 0;
        int pro = 1;

        for (int i = 0, j = 0; j < nums.size(); j++) {
            pro *= nums[j];

            while (i <= j && pro >= k) {
                pro = pro / nums[i++];
            }
            count = count + (j - i + 1);
        }
        return count;
    }
};