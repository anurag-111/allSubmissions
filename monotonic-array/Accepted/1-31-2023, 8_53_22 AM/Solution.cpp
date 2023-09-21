// https://leetcode.com/problems/monotonic-array

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool inc = false;
        bool dec = false;

        for (int i = 1; i < A.size(); i++) {
            if (A[i] < A[i - 1]) {
                dec = true;
            }
            if (A[i] > A[i - 1]) {
                inc = true;
            }
        }

        return inc && dec ? false : true;
    }
};