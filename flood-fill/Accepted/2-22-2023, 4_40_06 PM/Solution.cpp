// https://leetcode.com/problems/flood-fill

class Solution {
private:
    void DFS(vector<vector<int>>& image, int row, int col, int new_color, int old_color) {
        if(row < 0 || row >= image.size() || col < 0 || col >= image[0].size() || image[row][col] != old_color) {
            return;
        }

        image[row][col] = new_color;

        DFS(image, row + 1, col, new_color, old_color);
        DFS(image, row, col + 1, new_color, old_color);
        DFS(image, row - 1, col, new_color, old_color);
        DFS(image, row, col - 1, new_color, old_color);
    }


public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color == image[sr][sc]) {
            return image;
        }

        DFS(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};

// Time Complexity : O(row * col)
// Space Complexity : O(1)