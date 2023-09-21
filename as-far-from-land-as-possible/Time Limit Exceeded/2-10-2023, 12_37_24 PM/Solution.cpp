// https://leetcode.com/problems/as-far-from-land-as-possible

class Solution {
private:
    void helper(vector<vector<int>>& grid, int i, int j, int dist = 1) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || (grid[i][j] != 0 && grid[i][j] <= dist)) { 
            return;
        }
        grid[i][j] = dist;
        helper(grid, i - 1, j, dist + 1), helper(grid, i + 1, j, dist + 1), helper(grid, i, j - 1, dist + 1), helper(grid, i, j + 1, dist + 1);
}

public:
    int maxDistance(vector<vector<int>>& grid, int mx = -1) {
        if(!grid.size()) {
            return 0;
        }
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    helper(grid, i, j);
                }
            }
        }

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] > 1) {
                    mx = max(mx, grid[i][j] - 1);
                }
            }
        }
        return mx;
    }
};


// Approach :
// For each 'land' cell, start DFS and record the distance in 'water' cells.

// If the distance in the 'water' cell is smaller than the current distance, we stop there. Otherwise, we update the distance to the smaller value and keep going.

// Complexity :
// Runtime: O(m * n * n), where m is the number of land cells.
// Memory: O(n * n) for the recursion.