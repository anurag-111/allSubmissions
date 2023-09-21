// https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1

class Solution {
public:
    int gcd(int a, int b) {
        // Helper function to calculate the gcd of two numbers
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int total_cost = 0;

        for (int i = n - 1; i >= 0; i--) {
            // Iterate through the array from right to left
            int gcd_val = gcd(nums[i], i + 1);
            if (gcd_val > 1) {
                // If the gcd of nums[i] and i+1 is greater than 1,
                // update nums[i] with the gcd value
                nums[i] = gcd_val;
                total_cost ++; // Add the cost of the operation
            }
        }

        return total_cost;
    }


};


