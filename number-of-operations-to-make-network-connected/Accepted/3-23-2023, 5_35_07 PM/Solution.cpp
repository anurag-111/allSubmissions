// https://leetcode.com/problems/number-of-operations-to-make-network-connected

class Solution {
private:
    void dfs(vector<int> &visited, unordered_map<int, vector<int>> &adj_list, int curr) {
        visited[curr] = 1;

        for(auto i : adj_list[curr]) {
            if(visited[i] == -1) {
                dfs(visited, adj_list, i);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> visited(n, -1);
        unordered_map<int, vector<int>> adj_list;

        // Creation of adjacency list
        int edges = 0;
        for(int i = 0; i < connections.size(); i++) {
            adj_list[connections[i][0]].push_back(connections[i][1]);
            adj_list[connections[i][1]].push_back(connections[i][0]);
            edges++;
        }

        // Number of components
        int comp = 0;
        for(int i = 0; i < n; i++) {
            if(visited[i] == -1) {
                comp++;
                dfs(visited, adj_list, i);
            }
        }

        // Check for valid number of edges
        if(edges < n - 1) {
            return -1;
        } else {
            return comp - 1;
        }

        return -1;

    }
};

// Time Complexity : DFS -> O(V + E)