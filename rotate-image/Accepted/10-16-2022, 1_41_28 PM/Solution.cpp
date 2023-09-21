// https://leetcode.com/problems/rotate-image

class Solution {
public:
    void transpose(vector<vector<int>>& matrix) {
        for(int i = 0; i<matrix.size(); i++) {
            for(int j = 0; j<i; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp; 
            } 
        }
    }
    void reverse(vector<vector<int>>& matrix) {
        for(int i = 0; i<matrix.size(); i++) {
            int j = 0,k = matrix[i].size() - 1;
            while(j < k) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][k];
                matrix[i][k] = temp;
                j++;
                k--;
            }        
        }
    }
     void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverse(matrix);
     }
};