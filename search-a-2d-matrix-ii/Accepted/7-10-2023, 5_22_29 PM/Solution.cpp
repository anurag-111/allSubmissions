// https://leetcode.com/problems/search-a-2d-matrix-ii

class Solution {
public:
    /**
     * Search for the target value in a matrix.
     *
     * @param matrix The input matrix.
     * @param target The value to search for.
     * @return True if the target value is found, False otherwise.
     */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();                          // Number of rows in the matrix
        int cols = matrix[0].size();                       // Number of columns in the matrix

        int row = 0;                                       // Start at the top-right corner
        int col = cols - 1;

        while (row < rows && col >= 0) {
            if (matrix[row][col] == target) {
                // Target found
                return true;
            } else if (matrix[row][col] > target) {
                // Target is smaller, move left in the same row
                col--;
            } else {
                // Target is larger, move down to the next row
                row++;
            }
        }

        // Target not found
        return false;
    }
};


/*
    Time Complexity: O(N + M)

    The search starts from the top-right corner and moves left or down depending on the target value. 
    In the worst case, it either reaches the bottom-left corner or goes out of bounds. 
    Hence, the time complexity is O(N + M), where N is the number of rows and M is the 
    number of columns in the matrix.
    
    Space Complexity: O(1)

    The algorithm uses a constant amount of extra space for the variables rows, cols, row, and col.
    Therefore, the space complexity is O(1), indicating constant space usage regardless of the 
    input size.
    
*/