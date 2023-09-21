// https://leetcode.com/problems/equal-row-and-column-pairs

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();  // Number of rows or columns in the grid
        int count = 0;  // Variable to count the equal pairs

        vector<vector<int>> transposedGrid = grid;  // Create a copy of the original grid
        // Transpose the grid by swapping elements across the diagonal
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(grid[i][j], grid[j][i]);
            }
        }

        // Compare each row of the transposed grid with the rows of the original grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i] == transposedGrid[j]) {
                    count++;
                }
            }
        }
        
        return count;
    }
};
