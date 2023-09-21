// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> merged; // Vector to store the merged intervals
        sort(intervals.begin(), intervals.end()); // Sort the intervals based on the starting point
        
        merged.push_back(intervals[0]); // Add the first interval to the merged vector
        
        for (int i = 1; i < intervals.size(); i++) {
            
            vector<int> current = intervals[i]; // Current interval being processed
            vector<int> last = merged.back(); // Last merged interval
            
            if (current[0] <= last[1]) {
                // Case: Overlapping intervals, update the ending point of the last interval
                last[1] = max(current[1], last[1]); // Update the ending point to the maximum of current and last interval's ending point
                merged.pop_back(); // Remove the last interval from merged vector
                merged.push_back(last); // Add the updated interval back to the merged vector
            } else {
                // Case: Non-overlapping intervals, add the current interval to the merged vector
                merged.push_back(current);
            }
        }
        
        return merged; // Return the merged intervals
        
    }
};
