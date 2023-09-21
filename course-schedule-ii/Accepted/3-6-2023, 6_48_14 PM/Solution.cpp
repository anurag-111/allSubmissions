// https://leetcode.com/problems/course-schedule-ii

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> g(numCourses, vector<int>());
        int n = prerequisites.size();
        vector<int> indegree(numCourses, 0);

        for(int i = 0;i < n; i++) {
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        queue<int> q;
        for(int i = 0;i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> result;
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            result.push_back(v);
            vector<int> vec = g[v];
            numCourses--;
            
            for(int u : g[v]) {
                indegree[u]--;
                if(indegree[u] == 0) {
                    q.push(u);
                }
            }
        }
        if(numCourses == 0) {
            return result;
        }
        
        return vector<int>();
    }
    
    
};