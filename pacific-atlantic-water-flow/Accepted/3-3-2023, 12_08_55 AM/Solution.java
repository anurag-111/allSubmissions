// https://leetcode.com/problems/pacific-atlantic-water-flow

class Solution {
    
    private int rows;
    private int cols;
    private int[][] dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        
        if (heights == null || heights[0].length == 0) {
            return null;
        }
        
        rows = heights.length;
        cols = heights[0].length;

        int[][] pacific = new int[rows][cols];
        int[][] atlantic = new int[rows][cols];
        
        List<List<Integer>> result = new ArrayList<>();
        
        for (int col = 0; col < cols; col++) {
            dfs(0, col, heights, pacific, 0);
            dfs(rows - 1, col, heights, atlantic, 0);
        }
        
        for (int row = 0; row < rows; row++) {
            dfs(row, 0, heights, pacific, 0);
            dfs(row, cols - 1, heights, atlantic, 0);
        }
        
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (pacific[row][col] == 1 && atlantic[row][col] == 1) {
                    result.add(Arrays.asList(new Integer[]{row, col}));
                }
            }
        }
        
        return result;
    }
    
    private void dfs(int row, int col, int[][] heights, int[][] ocean, int prevHeight) {
        
        ocean[row][col] = 1;
        prevHeight = heights[row][col];
        
        for (int[] dir : dirs) {
            int nextRow = row + dir[0];
            int nextCol = col + dir[1];
            
            if (nextRow >= 0 && nextRow < rows && nextCol >= 0
               && nextCol < cols && ocean[nextRow][nextCol] != 1 &&
               prevHeight <= heights[nextRow][nextCol]) {
                dfs(nextRow, nextCol, heights, ocean, prevHeight);
            }
        }
    }
}