// https://leetcode.com/problems/path-with-maximum-probability

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // Create a graph using adjacency list representation
        vector<vector<pair<int, double>>> graph(n);  // Graph to store edges and probabilities
        
        // Build the graph using given edges and success probabilities
        for (int i = 0; i < edges.size(); i++) {
            vector<int> edge = edges[i];
            int u = edge[0];
            int v = edge[1];
            double p = succProb[i];
            graph[u].push_back({v, p});
            graph[v].push_back({u, p});
        }
        
        // Perform Dijkstra's algorithm using priority queue
        priority_queue<pair<double, int>> pq;  // Priority queue to store probabilities and nodes
        pq.push({1.0, start});  // Start node with probability 1.0
        
        vector<bool> visited(n, false);  // Track visited nodes
        
        while (!pq.empty()) {
            auto [prob, pos] = pq.top();
            pq.pop();
            
            if (pos == end)
                return prob;  // Reached the end node, return the maximum probability
            
            if (visited[pos])
                continue;  // Skip if the node has already been visited
            
            visited[pos] = true;
            
            // Explore neighbors and update probabilities
            for (auto [next, p] : graph[pos]) {
                pq.push({prob * p, next});
            }
        }
        
        return 0;  // Unable to reach the end node, return 0 as the maximum probability
    }
};
