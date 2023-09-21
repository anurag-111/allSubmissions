// https://leetcode.com/problems/max-area-of-island

class Solution {
private:
    int max_area = 0;
    int cur_area = 0;

    void search(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1) {
            return;
        }

        grid[i][j] = -1;
        cur_area++;
        
        search(grid, i + 1, j);
        search(grid, i, j + 1);
        search(grid, i - 1, j);
        search(grid, i, j - 1);
        

    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[0].size(); col++) {
                if(grid[row][col] == 1) {
                    cur_area = 0;
                    search(grid, row, col);
                    max_area = max(max_area, cur_area);
                }
            }
        }
        return max_area;
    }
};