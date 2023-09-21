// https://leetcode.com/problems/single-number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> umap;
        
        for(auto i : nums){
            umap[i]++;
        }
        for(auto key : umap){
            if(key.second == 1){
                return key.first;
            }
        }
        return -1;
    }
};