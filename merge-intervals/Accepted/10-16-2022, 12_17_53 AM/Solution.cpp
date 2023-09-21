// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end());
        merged.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            
            vector<int> current = intervals[i];
            vector<int> last = merged.back();
            
            if (current[0] <= last[1]) {
                last[1] = max(current[1], last[1]);
                merged.pop_back();
                merged.push_back(last);
            } else {
                merged.push_back(current);
            }
        }
        
        return merged;
        
    }
};