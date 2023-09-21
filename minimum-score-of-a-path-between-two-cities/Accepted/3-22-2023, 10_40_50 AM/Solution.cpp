// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities

class Solution {
public:
    void dfs(vector<vector<pair<int, int>>> &adj, int curr, vector<int> &vis, int &mi) {
        if (vis[curr]) {
            return;
        }
            

        vis[curr] = 1;
 
        for (auto nxt : adj[curr]) {
            mi = min(mi, nxt.second);
            dfs(adj, nxt.first, vis, mi);
        }
 
        return;
    }
    int minScore(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> adj(n + 1);
 
        for (int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
 
        int mi = INT_MAX;
        vector<int> vis(n + 1, 0);
        dfs(adj, 1, vis, mi);
 
        return mi;
    }
};