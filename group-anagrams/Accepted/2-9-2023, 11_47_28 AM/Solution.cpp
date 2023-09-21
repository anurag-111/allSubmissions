// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {    
        unordered_map<string, vector<string>> umap;
        vector<vector<string>> groupedAnagrams;
    
        for (string str : strs) { // n times where n  size of input array strs
           
            umap[mySort(str)].push_back(str);
            
        }
        
        for (auto itr : umap) {
            groupedAnagrams.push_back(itr.second);
        }
        
        return groupedAnagrams;
    }
    
    string mySort(string s) {
        
        int counts[26] = {0};
        
        for (char ch : s) {
            counts[ch - 'a']++;
        }
        
        string key = "";
        for (int c = 0; c < 26; c++) {
            if (counts[c] > 0) {
                key += ('a' + c);
                key += counts[c];
            }
        }
        
        return key;
    }
    
    
};