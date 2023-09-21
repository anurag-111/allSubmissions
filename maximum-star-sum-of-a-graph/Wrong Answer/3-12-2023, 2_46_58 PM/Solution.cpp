// https://leetcode.com/problems/maximum-star-sum-of-a-graph

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        if(edges.size() == 0) {
            int ans = INT_MIN;
            for(int i = 0; i < vals.size(); i++) {
                ans = max(ans, vals[i]);
            }
            return ans;
        }

        vector<vector<int>> adj_list(vals.size());
        int n = 0;

        for(int i = 0; i < edges.size(); i++) {
            int x = edges[i][0];
            int y = edges[i][1];

            adj_list[x].push_back(vals[y]);
            adj_list[y].push_back(vals[x]);
        }

        long long mx = 0;
        for(int i = 0; i < (int)adj_list.size(); i++) {
            long long ans = 0;
            sort(adj_list[i].rbegin(), adj_list[i].rend()); //sorting in descendig order

            for(int j = 0; j < min(k, (int)adj_list[i].size()); j++) {
                if(adj_list[i][j] > 0) {
                    ans += adj_list[i][j];
                }
            }
            ans += vals[i];
            mx = max(mx, ans);
        }
        return mx;        
    }
};