// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map <int, int> umap;
        int duplicate = 0;
        
        for(auto i : nums){
            umap[i]++;
        }
     
        for(auto key : umap){
            if(key.second > 1){
                duplicate = key.first;
                break;
            }
        }
        return duplicate;
    }
};