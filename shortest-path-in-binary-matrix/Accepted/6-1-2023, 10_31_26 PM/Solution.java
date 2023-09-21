// https://leetcode.com/problems/shortest-path-in-binary-matrix

class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        
        int[][] dirs = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
     
        if (grid == null || grid.length == 0 || grid[0].length == 0) {
            return -1;
        }
        
        if (grid[0][0] == 1) {
            return -1;
        }
        
        int rows = grid.length;
        int cols = grid[0].length;
        
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{0, 0, 1});

        
        while (!queue.isEmpty()) {
            
            int[] current = queue.remove();
            
            if (current[0] == rows - 1 && current[1] == cols - 1) {
                return current[2];
            }
            
            for (int[] dir : dirs) {
                int nextRow = current[0] + dir[0];
                int nextCol = current[1] + dir[1];
                
                if (nextRow >= 0 && nextRow < rows &&
                    nextCol >= 0 && nextCol < cols &&
                    grid[nextRow][nextCol] == 0) {
                    grid[nextRow][nextCol] = 1;
                    queue.add(new int[]{nextRow, nextCol, current[2] + 1});
                }
            }
        }
        
        return -1;
        
    }
}