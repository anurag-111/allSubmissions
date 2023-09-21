// https://leetcode.com/problems/number-of-islands

#include <vector>

class Solution {
private:
    // Depth-first search function to mark islands as visited
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Base cases for recursion
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }

        // Mark the current cell as visited by changing its value to '0'
        grid[i][j] = '0';

        // Perform DFS in all four directions
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
    }

public:
    // Function to calculate the number of islands in the grid
    int numIslands(vector<vector<char>>& grid) {
        int count = 0; // Variable to store the count of islands

        // Iterate through each cell in the grid
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // If an unvisited island is found, perform DFS and increment the count
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};
