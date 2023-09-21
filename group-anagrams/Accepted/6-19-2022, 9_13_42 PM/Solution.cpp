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
        for (string str : strs) {
            
            string key = str;
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