// https://leetcode.com/problems/smallest-range-ii

class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        

        int n = A.size();
        sort(A.begin(), A.end());
        int res = A[n - 1] - A[0];

        for (int i = 0; i < n - 1; i++) {
            int j = i + 1;
            int minimum = min(A[0] + K, A[j] - K);
            int maximum = max(A[n - 1] - K, A[i] + K);
            
            res = min(res, maximum - minimum);
        }
        return res;
    }
};