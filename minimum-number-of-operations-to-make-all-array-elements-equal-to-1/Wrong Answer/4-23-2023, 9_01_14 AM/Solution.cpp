// https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1

class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ops = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                continue;
            }
            if (i < n - 1 && nums[i + 1] != 1) {
                nums[i] = gcd(nums[i], nums[i + 1]);
                nums[i + 1] = 1;
                ops++;
            } else {
                int j = i;
                while (j >= 0 && nums[j] != 1) {
                    nums[j] = gcd(nums[j], nums[j + 1]);
                    nums[j + 1] = 1;
                    ops++;
                    j--;
                }
                if (j < 0) {
                    return -1;
                }
            }
        }
        return ops;
    }



};


