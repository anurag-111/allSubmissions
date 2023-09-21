// https://leetcode.com/problems/remove-covered-intervals

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // Sort intervals in ascending order based on start points
        sort(intervals.begin(), intervals.end());

        int nonCoveredCount = 1;  // Count of non-covered intervals
        int prevEnd = intervals[0][1];  // Keep track of the maximum end point encountered so far

        // Iterate through sorted intervals starting from the second interval
        for (int i = 1; i < intervals.size(); i++) {
            // If the current interval's end point is greater than prevEnd, it is not covered
            if (intervals[i][1] > prevEnd) {
                nonCoveredCount++;  // Increment the count of non-covered intervals
                prevEnd = intervals[i][1];  // Update prevEnd to the end point of the current interval
            }
        }

        return nonCoveredCount;
    }
};
