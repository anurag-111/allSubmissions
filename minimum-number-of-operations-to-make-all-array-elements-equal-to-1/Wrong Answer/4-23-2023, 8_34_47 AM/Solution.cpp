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
        int operations = 0;

        for (int i = 0; i < n - 1; i++) {
            int gcd_val = gcd(nums[i], nums[i + 1]);
            if (gcd_val > 1) {
                // If the gcd of nums[i] and nums[i + 1] is greater than 1,
                // replace either nums[i] or nums[i + 1] with the gcd value
                nums[i + 1] = gcd_val;
                operations++;
            }
        }

        // Check if all elements are equal to 1 after the operations
        for (int i = 0; i < n; i++) {
            if (nums[i] != 1) {
                return -1;
            }
        }

        return operations;
    }

};


