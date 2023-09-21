// https://leetcode.com/problems/shortest-path-with-alternating-colors

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {

        // Adjacency list adj that contains a list of pairs of integers 
        // such that adj[node] contains the neighbors of node in the form (neighbor, color)
        vector<vector<pair<int, int>>> adj(n);

        // We use the number 0 for red and the number 1 for blue.
        for (auto& redEdge : redEdges) {
            adj[redEdge[0]].push_back({redEdge[1], 0});
        }
        for (auto& blueEdge : blueEdges) {
            adj[blueEdge[0]].push_back(make_pair(blueEdge[1], 1));
        }

        // answer array with the value -1 where answer[i] 
        // is the answer for the i'th node
        vector<int> answer(n, -1);

        // a 2D visit array in which visit[node][color] indicates whether 
        // node has yet been visited using an edge of color.
        vector<vector<bool>> visit(n, vector<bool>(2));

        // a queue of triplets. It will save three integers per triplet: 
        // a) the current node, b) the steps taken to visit the node, and 
        // c) the color of the previous edge used.
        queue<vector<int>> q;

        // Start with node 0, with number of steps as 0 and undefined color -1.
        q.push({0, 0, -1});
        visit[0][1] = visit[0][0] = true;
        answer[0] = 0;

        while (!q.empty()) {
            auto element = q.front();
            int node = element[0], steps = element[1], prevColor = element[2];
            q.pop();

            for (auto& [neighbor, color] : adj[node]) {
                if (!visit[neighbor][color] && color != prevColor) {
                    visit[neighbor][color] = true;
                    q.push({neighbor, 1 + steps, color});
                    if (answer[neighbor] == -1) {
                        answer[neighbor] = 1 + steps;
                    }
                }
            }
        }
        return answer;
    }
};


// Time Complexity : O(n + e)
// Space Complexity : O(n + e)