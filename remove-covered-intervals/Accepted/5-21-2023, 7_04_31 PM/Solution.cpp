// https://leetcode.com/problems/remove-covered-intervals

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        // The custom comparator ensures that the intervals are sorted in ascending order based on 
        // their start points. If the start points are equal, the comparator considers the end points 
        // to determine the order. In this case, intervals with the same start point are sorted by 
        // their end points in descending order.
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        int notCoveredCount = 1;  // Count of non-covered intervals
        int prevEnd = intervals[0][1];  // Keep track of the maximum end point encountered so far

        // Iterate through sorted intervals
        for (int i = 1; i < intervals.size(); i++) {
            // If the current interval's end point is greater than prevEnd, it is not covered
            if (intervals[i][1] > prevEnd) {
                notCoveredCount++;  // Increment the count of non-covered intervals
                prevEnd = intervals[i][1];  // Update prevEnd to the end point of the current interval
            }
        }

        return notCoveredCount;
    }
};
