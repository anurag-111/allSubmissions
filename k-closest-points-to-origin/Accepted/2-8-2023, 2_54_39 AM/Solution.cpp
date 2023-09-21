// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    
        //creating a multimap : <Distance, Index of the co-ordinate>
        multimap<int, int> map;
        
        //calculating the distance and storing the index of its co-ordinate
        for(int i = 0; i < points.size(); i++) {
            map.insert({points[i][0] * points[i][0] + points[i][1] * points[i][1], i});
        }

        vector<vector<int>> ans;

        //storing first k points 
        int count = 0;
        for (auto itr = map.begin(); count < k; ++itr, count++) {
            ans.push_back(points[itr->second]);
        }

        return ans;
    }
};

//TC : O(nlogn)