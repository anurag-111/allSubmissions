// https://leetcode.com/problems/remove-covered-intervals

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) {
            return 0;
        }

        sort(intervals.begin(), intervals.end());

        int left = 0;
        int right = 1;
        int count = 0;

        while(right < intervals.size()) {
            if(intervals[left][0] >= intervals[right][0] && intervals[left][1] <= intervals[right][1]) {
                count++;
                right++;
                left = right;
            } 
        }

        return count;
    }
};