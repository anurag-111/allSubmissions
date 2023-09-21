// https://leetcode.com/problems/spiral-matrix

// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        vector<int> result;
       
        if(m == 0) {
            return result;
        } 

        int n = matrix[0].size();
        
        int top = 0, left = 0, right = n-1, bottom = m-1;
        
        
        while(top <= bottom && left <= right){
            
            for(int i = left; i <= right; i++){
                result.push_back(matrix[top][i]);
            }
            top++;
            
            for(int i = top; i <= bottom; i++){
                result.push_back(matrix[i][right]);
            }
            
            right--;
            
            if(top > bottom || right < left) {
                break;
            } 
            
            for(int i = right; i >= left; i--){
                result.push_back(matrix[bottom][i]);
            }
            
            bottom--;
            
            for(int i = bottom; i >= top; i--){
                result.push_back(matrix[i][left]);
            }
            left++;
        }
        return result;
    }
};