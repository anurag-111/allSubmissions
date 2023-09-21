// https://leetcode.com/problems/01-matrix

class Solution {
public:
    vector<int> DIR = {0, 1, 0, -1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        queue<pair<int, int>> q;

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                if (mat[r][c] == 0) {
                    q.push(make_pair(r, c));
                } else {
                    mat[r][c] = -1; // Not processed yet.
                }
            }
        }
                
                
        while (!q.empty()) {

            auto [r, c] = q.front(); // making a copy of the top element. Removing that element from q doesn't affect the copy.
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = r + DIR[i];
                int nc = c + DIR[i+1];

                if (nr < 0 || nr == row || nc < 0 || nc == col || mat[nr][nc] != -1) {
                    continue;
                }

                mat[nr][nc] = mat[r][c] + 1;
                q.emplace(nr, nc);
            }
        }
        return mat;
    }
};
