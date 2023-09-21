// https://leetcode.com/problems/island-perimeter

class Solution {
private:
    int count = 0;

    void dfs(vector<vector<int>>& grid, int i, int j) {

        // counting the perimeters of the particular grid cell
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            count++;
            return;
        }

        // return, if the grid cell has already been visited
        if(grid[i][j] == -1) {
            return;
        }

        // marking the visited grid cell with -1
        grid[i][j] = -1;

        // search in all the four possible directions
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        count = 0;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j);
                    break;
                }
            }
        }

        return count;
    }
};


// Time complexity is O(M*N)
// Space complexity is O(1)