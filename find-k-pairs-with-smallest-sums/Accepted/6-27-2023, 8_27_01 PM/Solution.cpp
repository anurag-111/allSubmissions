// https://leetcode.com/problems/find-k-pairs-with-smallest-sums

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> res;
        vector<int> temp(n, 0);
        set<vector<int>> pq;
        pq.insert({nums1[0] + nums2[0], nums1[0], nums2[0], 0, 0}); 
        while(k-- && !pq.empty())
        {
            vector<int> itr = *pq.begin();
            int a = itr[1], b = itr[2], c = itr[3], d = itr[4];
            res.push_back({a, b});
            if(d + 1 < m)
            {
                pq.insert({nums1[c] + nums2[d + 1], nums1[c], nums2[d + 1], c, d + 1});
            }
            if(c + 1 < n)
            {
                pq.insert({nums1[c + 1] + nums2[temp[c + 1]], nums1[c + 1], nums2[temp[c + 1]], c + 1, temp[c + 1]});
                temp[c + 1]++;
            }
            pq.erase(pq.begin());
        }
        return res;
    }
};