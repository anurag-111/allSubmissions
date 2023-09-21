// https://leetcode.com/problems/shortest-bridge

class Solution {
public:
    const int directions[5] = {0, 1, 0, -1, 0};

    void paint(vector<vector<int>>& grid, int i, int j, vector<pair<int, int>>& queue) {
        if (min(i, j) >= 0 && max(i, j) < grid.size() && grid[i][j] == 1) {
            grid[i][j] = 2;
            queue.push_back({i, j});
            for (int d = 0; d < 4; ++d) {
                paint(grid, i + directions[d], j + directions[d + 1], queue);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        vector<pair<int, int>> queue;
        for (int i = 0; queue.size() == 0 && i < grid.size(); ++i) {
            for (int j = 0; queue.size() == 0 && j < grid[0].size(); ++j) {
                paint(grid, i, j, queue);
            }
        }
        while (!queue.empty()) {
            vector<pair<int, int>> newQueue;
            for (auto [i, j] : queue) {
                for (int d = 0; d < 4; ++d) {
                    int x = i + directions[d];
                    int y = j + directions[d + 1];
                    if (min(x, y) >= 0 && max(x, y) < grid.size()) {
                        if (grid[x][y] == 1) {
                            return grid[i][j] - 2;
                        }
                        if (grid[x][y] == 0) {
                            grid[x][y] = grid[i][j] + 1;
                            newQueue.push_back({x, y});
                        }
                    }
                }
            }
            swap(queue, newQueue);
        }
        return 0;
    }

};