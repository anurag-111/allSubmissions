// https://leetcode.com/problems/first-completely-painted-row-or-column

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> row(n), col(m);
        vector<int> my_row(n * m), my_col(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j]--;
                my_row[mat[i][j]] = i;
                my_col[mat[i][j]] = j;
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            int x = arr[i]; --x;
            row[my_row[x]]++;
            col[my_col[x]]++;
            if (row[my_row[x]] == m || col[my_col[x]] == n) return i;
        }
        return -1;
    }
};