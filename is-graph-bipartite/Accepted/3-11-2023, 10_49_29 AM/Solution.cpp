// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<vector<int>> adj(n,vector<int>());
        bool isbipartite = true;

        for(int i = 0; i < n; i++){
            for(int j = 0;j < graph[i].size(); j++){
                adj[i].push_back(graph[i][j]);
            }
        }

        vector<int> color(n, -1);
        queue<int> q;
        
        for(int st = 0; st < n; st++) {

            if(color[st] == -1) {
                q.push(st);
                color[st] = 0;
                while(!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for(int v : adj[u]) {
                        if(color[v] == -1){
                            color[v] = 1 - color[u];
                            q.push(v);
                        } else {
                            isbipartite &= color[u] !=color[v];
                        }
                    }
                }
            }
        }
        return isbipartite;
    }
};