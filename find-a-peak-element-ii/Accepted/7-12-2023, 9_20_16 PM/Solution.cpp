// https://leetcode.com/problems/find-a-peak-element-ii

class Solution {
private:
    int calculateMax(vector<int>& array, int end) {
        int maxVal = INT_MIN;
        int pos = -1;
        for (int i = 0; i <= end; i++) {
            if (array[i] > maxVal) {
                maxVal = array[i];
                pos = i;
            }
        }
        return pos;
    }

public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        int startRow = 0;
        int endRow = rows - 1; 

        while (startRow <= endRow) {
            int midRow = startRow + (endRow - startRow) / 2;

            int maxMidRow = calculateMax(mat[midRow], cols - 1); 

            if (midRow == 0) {
                if (mat[midRow][maxMidRow] > mat[midRow + 1][maxMidRow]) {
                    return {midRow, maxMidRow};
                }
            }

            if (midRow == rows - 1) {
                if (mat[midRow][maxMidRow] > mat[midRow - 1][maxMidRow]) {
                    return {midRow, maxMidRow};
                }
            }

            if (mat[midRow][maxMidRow] > mat[midRow + 1][maxMidRow] && mat[midRow][maxMidRow] > mat[midRow - 1][maxMidRow]) {
                return {midRow, maxMidRow};
            }

            if (mat[midRow][maxMidRow] < mat[midRow + 1][maxMidRow]) {
                startRow = midRow + 1; 
            } else {
                endRow = midRow - 1;
            }
        }

        // No peak element found in the matrix
        return {-1, -1};
    }
};
