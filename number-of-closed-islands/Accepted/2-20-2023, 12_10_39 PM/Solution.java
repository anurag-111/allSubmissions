// https://leetcode.com/problems/number-of-closed-islands

class Solution {

    public int closedIsland(int[][] grid) {
        int count = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(i, j, grid)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }

    private boolean dfs(int i, int j, int[][] grid) {
        if (i < 0 || j < 0 || i >= grid.length || j >= grid[0].length) {
            return false;
        }

        if (grid[i][j] == 1) {
            return true;
        }

        grid[i][j] = 1;

        
        boolean d1 = dfs(i+1, j, grid);
        boolean d2 = dfs(i, j+1,grid);
        boolean d3 = dfs(i-1, j, grid);
        boolean d4 = dfs(i, j-1, grid);
        return d1 && d2 && d3 && d4;
    }
}