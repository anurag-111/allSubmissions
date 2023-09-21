// https://leetcode.com/problems/check-if-it-is-a-straight-line

class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        int x = coordinates[1][0] - coordinates[0][0]; // Calculate x difference between the second and first points
        int y = coordinates[1][1] - coordinates[0][1]; // Calculate y difference between the second and first points

        for (int i = 2; i < coordinates.length; i++) {
            // Check if the current coordinate's x-difference multiplied by y
            // is equal to the current coordinate's y-difference multiplied by x
            if ((coordinates[i][0] - coordinates[0][0]) * y != (coordinates[i][1] - coordinates[0][1]) * x) {
                return false; // If the condition is not satisfied, the coordinates do not form a straight line
            }
        }

        return true; // If the loop completes without returning false, all coordinates lie on the same line
    }
}
