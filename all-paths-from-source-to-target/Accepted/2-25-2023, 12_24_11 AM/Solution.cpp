// https://leetcode.com/problems/all-paths-from-source-to-target

class Solution {
public:
    
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& result, vector<int> &path, int u){
        path.push_back(u);

        if(u == graph.size() - 1) {
            result.push_back(path);
        } else {
            for(int neigh : graph[u]){
                dfs(graph, result, path, neigh);
            }
        }
        
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> result;
        vector<int> path;
        
        if(graph.size() == 0) {
            return result;
        } 
        
        dfs(graph, result, path, 0);
        return result; 
    }
};