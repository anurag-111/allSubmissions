// https://leetcode.com/problems/number-of-enclaves

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int, int>> enclaves;
        int grid_row = grid.size();
        int grid_col = grid[0].size();
        vector<vector<int>> visited(grid_row, vector<int> (grid_col, 0));
    
         
        // Traversal for the boundaries 1's
        for(int i = 0; i < grid_row; i++) {
            for(int j =0; j < grid_col; j++) {
                if(i == 0 || j == 0 || i == grid_row - 1 || j == grid_col - 1) {
                     if(grid[i][j] == 1) {
                         // Inserting the index of the 1 found
                         enclaves.push({i, j});

                         // Marking the 1 found in the visited array
                         visited[i][j] = 1;     
                     }
                }
            }
        }

        int dir_row[] = {-1, 0, +1, 0};
        int dir_col[] = {0, +1, 0, -1};

        while(!enclaves.empty()) {
            int row = enclaves.front().first;
            int col = enclaves.front().second;
            enclaves.pop();

            // Traversal in all the 4 directions
            for(int i = 0; i < 4; i++) {
                int nrow = row + dir_row[i];
                int ncol = col + dir_col[i];

                // Check for valid coordinates and for land cell
                if(nrow >= 0 && nrow < grid_row && ncol >= 0 && ncol < grid_col && 
                    visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                            enclaves.push({nrow, ncol});
                            visited[nrow][ncol] = 1;
                }
            }
        }

        // Check for the number of land cells in grid for which we cannot walk off the 
        // boundary of the grid in any number of moves.
        int count = 0;
        for(int i = 0; i < grid_row; i++) {
            for(int j = 0; j < grid_col; j++) {
                // Check for unvisited land cell
                if(grid[i][j] == 1 && visited[i][j] == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};


// Time Complexity: O(NxMx4) ~ O(N x M) :

//     For the worst case, assuming all the pieces as land, the BFS function will be called for (N x M) nodes 
//     and for every node, we are traversing for 4 neighbors, so it will take O(N x M x 4) time. 

// Space Complexity ~ O(N x M) :

//     O(N x M) for the visited array, and queue space takes up N x M locations at max. 