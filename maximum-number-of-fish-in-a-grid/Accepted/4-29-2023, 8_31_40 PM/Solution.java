// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid

class Solution {
    int gMax = 0;
    int lMax = 0;
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    
    public int findMaxFish(int[][] grid) {
        
        int rows = grid.length;
        int cols = grid[0].length;
        boolean[][] visited = new boolean[rows][cols];
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(!visited[i][j] && grid[i][j] > 0){
                    lMax = 0;
                    dfs(i, j, grid, visited);
                    gMax = Math.max(gMax, lMax);
                } 
            }
        }
        return gMax;            
    }
    
    public void dfs(int i, int j, int[][] grid, boolean[][] visited) {
        lMax += grid[i][j];
        visited[i][j] = true;
        for(int k = 0; k < 4; k++) {
            int nextRow = i + dx[k];
            int nextCol = j + dy[k];
            if(nextRow >= 0 && nextRow < grid.length && nextCol >= 0 && nextCol < grid[0].length && !visited[nextRow][nextCol] && grid[nextRow][nextCol] > 0) {
                dfs(nextRow, nextCol, grid, visited);
            }
        }
    }
}