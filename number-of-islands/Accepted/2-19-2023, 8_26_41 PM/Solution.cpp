// https://leetcode.com/problems/number-of-islands

class Solution {
private:
    void dfs_grid(vector<vector<char>>& grid, int i, int j) {

        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';

        dfs_grid(grid, i + 1, j);
        dfs_grid(grid, i, j + 1);
        dfs_grid(grid, i - 1, j);
        dfs_grid(grid, i, j - 1);
        
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    dfs_grid(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};

// Time complexity -  O(m * n)
// Space complexity - O(m * n)
