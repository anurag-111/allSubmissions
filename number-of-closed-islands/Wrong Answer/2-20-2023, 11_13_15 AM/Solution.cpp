// https://leetcode.com/problems/number-of-closed-islands

class Solution {
private:
    int flag = 0;
    bool search(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return false;
        } 
        if(grid[i][j] == 1 || grid[i][j] == -1){
            return true;
        }

        grid[i][j] = -1; // visited

        return search(grid, i + 1, j) && search(grid, i, j + 1) && search(grid, i - 1, j) && search(grid, i, j - 1);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0) {
                    if (search(grid, i, j)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};