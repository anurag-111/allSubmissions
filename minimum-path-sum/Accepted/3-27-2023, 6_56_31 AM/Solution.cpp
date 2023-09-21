// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        if(grid.size() == 0) {
            return 0;
        }
    
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> cost(m, vector<int>(n));
        
        cost[0][0] = grid[0][0];
        
        for(int i=1;i<m;i++) {
            cost[i][0] = grid[i][0] + cost[i-1][0];
        }
        
        for(int j=1;j<n;j++) {
            cost[0][j] =  grid[0][j] + cost[0][j-1];
        }
            
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                cost[i][j] = grid[i][j] + min(cost[i - 1][j], cost[i][j - 1]);
            }
        }
        
        // Sum of all numbers along the path :
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<cost[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return cost[m - 1][n - 1];
    }
};