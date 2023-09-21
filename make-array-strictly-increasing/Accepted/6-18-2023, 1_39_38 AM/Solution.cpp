// https://leetcode.com/problems/make-array-strictly-increasing

class Solution {
public:
    int solve(int i, int j, int& len1, int& len2, int prev, vector<vector<int>>& dp, vector<int>& nums1, vector<int>& nums2) {
        if (i == len1) {
            return 0; // Reached the end of nums1, return 0 as no more elements to consider
        }

        // Find the next valid index in nums2 using binary search
        j = upper_bound(nums2.begin() + j, nums2.end(), prev) - nums2.begin();

        if (dp[i][j] != -1)
            return dp[i][j]; // If the subproblem has already been solved, return the precomputed result

        if (j == len2 && nums1[i] <= prev)
            return 2001; // If reached the end of nums2 and nums1[i] is not greater than prev, return an arbitrary large value (indicating not possible)

        int take = 2001, notTake = 2001;
        if (j != len2)
            take = solve(i + 1, j + 1, len1, len2, nums2[j], dp, nums1, nums2) + 1; // Try taking the element from nums2 and move to the next indices

        if (nums1[i] > prev)
            notTake = solve(i + 1, j, len1, len2, nums1[i], dp, nums1, nums2); // Skip nums1[i] and move to the next index

        return dp[i][j] = min(take, notTake); // Store the result in dp table and return the minimum of take and notTake
    }

    int makeArrayIncreasing(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, -1)); // dp table to store intermediate results

        sort(nums2.begin(), nums2.end()); // Sort nums2 in ascending order for binary search

        int result = solve(0, 0, len1, len2, -1, dp, nums1, nums2); // Call the recursive solve function
        if (result > len1)
            return -1; // If the result is greater than the length of nums1, it means it's not possible to make nums1 strictly increasing

        return result; // Return the minimum number of operations required to make nums1 strictly increasing
    }
};
