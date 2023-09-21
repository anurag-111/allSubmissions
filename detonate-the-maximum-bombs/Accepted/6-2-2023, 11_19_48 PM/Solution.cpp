// https://leetcode.com/problems/detonate-the-maximum-bombs

#define ll long long int

class Solution {
public:
    // Depth First Search (DFS) to traverse the graph and count the number of nodes
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int& count, int& node) {
        visited[node] = true;  // Mark the current node as visited
        count++;  // Increment the count of nodes visited

        // Traverse all the neighbors of the current node
        for (int j = 0; j < graph[node].size(); j++) {
            int neighbor = graph[node][j];
            if (!visited[neighbor]) {
                // Recursive call to visit the unvisited neighbors
                dfs(graph, visited, count, neighbor);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();  // Number of bombs

        // Create an adjacency list to represent the graph
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++) {
            ll x1, y1, r1;
            x1 = bombs[i][0];
            y1 = bombs[i][1];
            r1 = bombs[i][2];

            // Check if other bombs are within the range of explosion
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    ll x, y;
                    x = abs(x1 - bombs[j][0]);
                    y = abs(y1 - bombs[j][1]);

                    // If the distance is within the explosion radius, add it to the adjacency list
                    if (x * x + y * y <= r1 * r1) {
                        graph[i].push_back(j);
                    }
                }
            }
        }

        int maxDetonation = INT_MIN;  // Maximum detonation count

        // Perform DFS on each bomb to find the maximum detonation count
        for (int i = 0; i < n; i++) {
            int count = 0;
            vector<bool> visited(n, false);  // Keep track of visited nodes during DFS
            dfs(graph, visited, count, i);
            maxDetonation = max(maxDetonation, count);
        }

        return maxDetonation;
    }
};
