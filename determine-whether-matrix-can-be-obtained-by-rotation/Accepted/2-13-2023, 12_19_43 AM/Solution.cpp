// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        // rotation by 0 degree
        if(mat == target) {                                 
            return true;
        }
        
        // more rotations with 90, 180, 270 degree's
        int degree = 3;                          
        
        while(degree --) {
            
            // transpose
            for(int i = 0; i < n; i ++) {
                for(int j = i; j < n; j ++) {
                   int temp = mat[i][j];  
                   mat[i][j] = mat[j][i];
                   mat[j][i] = temp;
                }
            }
            
            // reverse
            for(int i = 0; i < n; i ++) {
                reverse(mat[i].begin(), mat[i].end());       // reverse each row.
            }
            
            // check
            if(mat == target) {
                return true;
            }
        }
        return false;
    }
};