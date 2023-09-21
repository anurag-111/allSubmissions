// https://leetcode.com/problems/insert-interval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();

        //Case 1 : no overlap before the newInterval
        while(i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        //Case 2 : overlapping occurs
        vector<int> mergeInt = newInterval;
        while(i < n && intervals[i][0] <= newInterval[1]) {
            mergeInt[0] = min(intervals[i][0], mergeInt[0]);
            mergeInt[1] = max(intervals[i][1], mergeInt[1]);
            i++;
        }

        result.push_back(mergeInt);

        //Case 3 : no overlap after the newInterval
        while(i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;

    }
};