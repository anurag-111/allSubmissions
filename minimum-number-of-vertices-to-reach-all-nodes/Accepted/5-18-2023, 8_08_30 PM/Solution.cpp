// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> res, seen(n); // Vector to store the result and a vector to mark nodes as seen or unseen

        // Mark the destination nodes of each edge as seen
        for (auto& e: edges) {
            seen[e[1]] = 1; // Mark the node as seen
        }
            
        // Iterate through all nodes
        for (int i = 0; i < n; ++i) {
            if (seen[i] == 0) {
                res.push_back(i); // Add the node to the result if it is unseen (not marked)
            }
        }

        return res; // Return the result
    }
};
