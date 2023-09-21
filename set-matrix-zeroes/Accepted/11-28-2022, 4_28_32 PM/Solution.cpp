// https://leetcode.com/problems/set-matrix-zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        set<int> rows ;
        set<int> cols ;
        
        // We mark the rows and columns that are to be made zero
        
        for (int i = 0; i < r; i++) {
          for (int j = 0; j < c; j++) {
            if (matrix[i][j] == 0) {
                rows.insert(i);
                cols.insert(j);
            }
          }
        }
        
        // Iterate over the array once again and using the rows and cols sets, update         the elements.
        
        for (int i = 0; i < r; i++)  {
          for (int j = 0; j < c; j++) {
            if (rows.count(i) || cols.count(j)) {
              matrix[i][j] = 0;
            }
          }
        }
    }
};