// https://leetcode.com/problems/merge-intervals

class Solution {
    public :
        vector<vector<int>> merge(vector<vector<int>> &intervals) {
            if(intervals.empty()) {
                return {};
            }

            // Sorting in increasing order of the starting time of an interval
            sort(intervals.begin(), intervals.end());

            // Creating a result vector
            vector<vector<int>> result;

            // Inserting the first interval
            result.push_back(intervals[0]);
            int j = 0;
            
            // Iterating over the intervals
            for(int i = 0; i < intervals.size(); i++) {
               
                // Overlapping occurs
                if(result[j][1] >= intervals[i][0]) {
                    result[j][1] = max(result[j][1], intervals[i][1]);
                } 
               
                // Else they are not overlapping
                else {
                    j++;
                    result.push_back(intervals[i]);
                }
            }

            return result;
        }
};