// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int low = 0;
        int high = (row * col) - 1;
        
        while (low <= high) {
            int mid = (low + high) >> 1;
            int stored = matrix[mid / col][mid % col];
            
            if (stored == target) {
                return true;
            } else if (stored > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
};