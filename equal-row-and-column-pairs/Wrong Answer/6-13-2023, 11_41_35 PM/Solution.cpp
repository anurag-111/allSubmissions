// https://leetcode.com/problems/equal-row-and-column-pairs

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int r = 0;

        vector<vector<int>> c = grid;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid.size(); j++) {
                swap(grid[i][j], grid[j][i]);
            }
        }
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid.size(); j++) {
                if(grid[i] == c[j]); {
                    r++;
                }
            }
        }
        return r;
    }
};