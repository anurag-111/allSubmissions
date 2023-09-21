// https://leetcode.com/problems/find-if-path-exists-in-graph

class Solution {
public:
    
    bool dfs(vector<vector<int>>& adj_list, vector<int>& visited, int current, int end) {
        
        // If the source an destination have a valid path
        if(current == end) {
            return true;
        }
            
        // Already marked
        if(visited[current]) {
            return false;
        }
           
        
        // Markig it as visited
        visited[current] = 1;
        
        // Applying DFS to search for the valid path
        for(int i=0; i < adj_list[current].size(); i++){
            if(dfs(adj_list, visited, adj_list[current][i], end)) {
                return true;
            }
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        
        vector<vector<int>> adj_list(n);
        
        // Creating adjacency list for the undirected graph
        for(int i = 0; i < edges.size(); i++) {
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }

       // Creating a visited array
        vector<int> visited(n, 0);
    
        return dfs(adj_list, visited, start, end);
    }
};