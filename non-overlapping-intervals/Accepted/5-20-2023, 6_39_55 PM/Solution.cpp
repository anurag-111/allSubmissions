// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); // Sort all intervals in ascending order
        int count = 0; // Count of number of intervals to be removed
        int n = intervals.size(); // Number of intervals
        int left = 0; // Index of the left interval
        int right = 1; // Index of the right interval
        
        while (right < n) { // Continue until all intervals are compared
            if (intervals[left][1] <= intervals[right][0]) {
                // Non-overlapping case: No overlap, move to the next pair
                left = right;
                right++;
            } else if (intervals[left][1] <= intervals[right][1]) {
                // Overlapping case 1: Remove the right interval as it extends beyond or ends at the same time as the left interval
                count++;
                right++;
            } else {
                // Overlapping case 2: Remove the left interval as it completely contains the right interval
                count++;
                left = right;
                right++;
            }
        }
        
        return count;
    }
};
