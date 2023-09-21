// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0, left = 0, right = 1, size = intervals.size();
        
        sort(intervals.begin(), intervals.end());
        while(right < size) {
            //case 1:
            if(intervals[left][1] <= intervals[right][0]) {
                left = right;
                right++;
            }
            //case 2:
            else if(intervals[left][1] <= intervals[right][1]) {
                count++;
                right++;
            }
            //case 3:
            else if(intervals[left][1] > intervals[right][1]) {
                count++;
                left = right;
                right++;
            }
        }
        return count;
    }
};

// Case 1:- Non-overlapping
// ------------------   -----------------
// |   Interval 1   |   |   Interval 2  |
// ------------------   -----------------

//Case 2:- Partial Overlapping
// ------------------
// |   Interval 1   |
// ------------------
//            ------------------
//            |    Interval 2  |
//            ------------------

//Case 3:- Complete Overlapping
//  --------------------
//  |    Interval 1    |
//  --------------------
//     --------------
//     | Interval 2 |
//     --------------
