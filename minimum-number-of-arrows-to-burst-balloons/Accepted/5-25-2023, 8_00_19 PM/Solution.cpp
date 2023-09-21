// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // Sort points based on the starting position
        sort(points.begin(), points.end());
        
        int lastEnd = points[0][1];
        int arrowCount = 1;

        for (auto& currentPoint : points) {
            if (currentPoint[0] > lastEnd) {
                arrowCount++;
                lastEnd = currentPoint[1];
            }
            lastEnd = min(lastEnd, currentPoint[1]);
        }       

        return arrowCount;
    }
};


// The variable `arrowCount` is initialized to 1 because initially, we assume that at least one arrow is needed to shoot down the balloons. As we iterate through the balloons, we may find that additional arrows are required if the current balloon does not overlap with the previous one. By starting with `arrowCount = 1`, we ensure that even if there is only one balloon, we will shoot it down with at least one arrow.

