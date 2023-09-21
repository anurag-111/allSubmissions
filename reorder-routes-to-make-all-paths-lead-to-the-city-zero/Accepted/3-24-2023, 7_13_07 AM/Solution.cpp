// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> forward_edges(n);
        vector<vector<int>> backward_edges(n);
        vector<int> visited(n);
        queue<int> que;
        int count = 0;
        que.push(0);

        for(auto itr : connections) {
            forward_edges[itr[0]].push_back(itr[1]);
            backward_edges[itr[1]].push_back(itr[0]);
        }

        while(!que.empty()) {
            int current = que.front();
            que.pop();
            visited[current] = 1;

            for(int edge : forward_edges[current]) {
                if(!visited[edge]) {
                    count++;
                    que.push(edge);
                }
            }

            for(int edge : backward_edges[current]) {
                if(!visited[edge]) {
                    que.push(edge);
                }
            }
        }
        return count;
    }
};