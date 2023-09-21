// https://leetcode.com/problems/longest-consecutive-sequence

// Time Complexity : O(n log n)
// Space Complexity : O(1)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        // Sort the numbers in ascending order
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int previousNumber = INT_MIN;
        int currentStreak = 0;
        int longestStreak = 0;

        for (int i = 0; i < n; i++) {
            if (previousNumber == nums[i] - 1) {
                // Current number is consecutive to the previous number
                currentStreak++;
            } else if (previousNumber != nums[i]) {
                // Current number is not equal to the previous number
                // Reset the streak to 1
                currentStreak = 1;
            }

            previousNumber = nums[i];
            longestStreak = max(longestStreak, currentStreak);
        }

        return longestStreak;
    }
};
