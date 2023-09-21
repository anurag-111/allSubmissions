// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph

class Solution {
public:
    void dfs(vector<int> adj[], int src, vector<bool> &vis,int &counter){
        if(vis[src]) {
            return;
        }

        vis[src] = true;
        counter++;

        for(auto itr : adj[src]){
            if(!vis[itr]){
                dfs(adj, itr, vis, counter);
            }
        }

    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];

        for(auto itr : edges){
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }

        long long res = 0;
        vector<bool> vis(n, false);
        vector<int> temp;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                int counter = 0;
                dfs(adj, i, vis, counter);
               temp.push_back(counter);
            }
        }

        int total = 0;
        for(int i = 0; i < temp.size(); i++){
            res += (long)((long)temp[i] * (long)(n-total-temp[i]));
            total += temp[i];
        }

        return res;
    }
};

// Complexity

// Time complexity:
// DFS takes O(V+E) for a graph represented using adjacency list.

// Space complexity:
// O(V) as we are using a stack to store the vertices.
// O(N) for making temp array