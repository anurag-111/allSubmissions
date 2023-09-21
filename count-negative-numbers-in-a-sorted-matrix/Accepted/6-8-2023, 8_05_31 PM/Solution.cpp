// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int negatives = 0;  // Counter for negative numbers
        int rows = grid.size();  // Number of rows in the grid
        int columns = grid[0].size();  // Number of columns in the grid

        for (int i = 0, right = columns - 1; i < rows; i++) {
            int left = 0;  // Leftmost index in the current row

            // Binary search to find the rightmost negative number in the row
            while (left <= right) {
                int middle = left + (right - left) / 2;
                if (grid[i][middle] < 0) {
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            }

            // Add the count of negatives in the current row to the overall count
            negatives += columns - left;
        }

        return negatives;  // Return the total count of negative numbers
    }
};