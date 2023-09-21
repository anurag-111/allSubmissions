// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int left = 0, count = 0, right = 1;
        sort(intervals.begin(), intervals.end());

        while(right < intervals.size()) {
            if(intervals[left][1] <= intervals[right][0]) {
                // Non-overlapping case
                left = right;
                right++;
            } else if(intervals[left][1] <= intervals[right][1]) {
                // Overlapping case 1
                count++;
                right++;
            } else {
                // Overlapping case 2
                // if(intervals[left][1] > intervals[right][1])
                count++;
                left = right;
                right++;
            }
        }

        return count;
    }
};