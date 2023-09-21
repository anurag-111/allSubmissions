// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    /**
     * Search for the target value in a 2D matrix.
     * 
     * @param matrix The input matrix.
     * @param target The value to search for.
     * @return True if the target value is found, False otherwise.
     */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();                      // Number of rows in the matrix
        int cols = matrix[0].size();                   // Number of columns in the matrix

        int low = 0;                                   // Starting index of the search range
        int high = (rows * cols) - 1;                  // Ending index of the search range

        while (low <= high) {
            int mid = low + (high - low) / 2;           // Calculate the middle index
            int midRow = mid / cols;                    // Row index of the middle element
            int midCol = mid % cols;                    // Column index of the middle element

            int stored = matrix[midRow][midCol];        // Value stored at the middle element

            if (stored == target) {
                // Target found
                return true;
            } else if (stored < target) {
                // Target is in the upper range
                low = mid + 1;                          // Adjust the low pointer
            } else {
                // Target is in the lower range
                high = mid - 1;                         // Adjust the high pointer
            }
        }

        // Target not found
        return false;
    }
};


/*
    Time Complexity: O(log (M * N))

    Space Complexity: O(1)

*/