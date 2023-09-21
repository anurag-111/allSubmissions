// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> umap;
        vector<vector<string>> groupedAnagrams;
        // // [    ["bat"],
        //         ["nat","tan"],
        //         ["ate","eat","tea"]  
        //     ]
        for (string str : strs) { // n times where n  size of input array strs
            
            // let m = size of largest string in 'strs'
            
            string key = str;
            // mlogm where m is size of largest string in input
            sort(key.begin(), key.end());
            
            // vector<string> values = umap[key];
            // values.push_back(str);
            // umap[key] = values;
            umap[key].push_back(str);
            
        }
        
        for (auto itr : umap) {
            groupedAnagrams.push_back(itr.second);
        }
        
        return groupedAnagrams;
        
    }
};