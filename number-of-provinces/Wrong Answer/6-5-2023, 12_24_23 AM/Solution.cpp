// https://leetcode.com/problems/number-of-provinces

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.empty()) {
            return 0;
        }

        int n = isConnected.size();
        vector<int> visited(n, -1);
        int groups = 0;

        for (int i = 0; i < visited.size(); i++) {
            if(visited[i] == -1){
                groups++;
                dfs(i, isConnected, visited);
            }
        }

        return groups;
    }

private:
    void dfs(int i, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[i] = 1;
        for (int j = 0; j < visited.size(); j++) {
            if (i != j && isConnected[i][j] && !visited[j]) {
                dfs(j, isConnected, visited);
            }
        }
    }
};