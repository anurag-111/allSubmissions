// https://leetcode.com/problems/find-right-interval

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        // Create a map to store the starting points of intervals and their corresponding indices
        map<int, int> startPoints;

        // Create a vector to store the result
        vector<int> result;

        // Process intervals and populate the map
        for (int i = 0; i < intervals.size(); i++) {
            startPoints[intervals[i][0]] = i;
        }

        // Find the right interval for each interval in the input vector
        for (int i = 0; i < intervals.size(); i++) {
            // Use lower_bound to find the first interval with a starting point greater than or equal to the current interval's ending point
            auto it = startPoints.lower_bound(intervals[i][1]);

            if (it != startPoints.end()) {
                // A right interval is found, push its index into the result vector
                result.push_back(it->second);
            } else {
                // No right interval found, push -1 into the result vector
                result.push_back(-1);
            }
        }

        return result;
    }
};
