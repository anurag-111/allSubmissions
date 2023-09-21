// https://leetcode.com/problems/number-of-islands

class Solution {
    public int numIslands(char[][] grid) {
        int count = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == '1') {
                    dfs_grid(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }

    private void dfs_grid(char[][] grid, int i, int j) {
        if (i >= 0 && i < grid.length && j < grid[0].length && j >= 0 && grid[i][j] == '1') {
            grid[i][j] = '0';
            dfs_grid(grid, i + 1, j);
            dfs_grid(grid, i-1, j);
            dfs_grid(grid, i, j + 1);
            dfs_grid(grid, i, j - 1);
        }
    }
}