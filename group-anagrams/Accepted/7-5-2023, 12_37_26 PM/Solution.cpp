// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> umap;

        for(auto str : strs) {
            string temp = str;
            sort(str.begin(), str.end());
            umap[str].push_back(temp);
        }

        for(auto str : umap) {
            ans.push_back(str.second);
        }
        return ans;
    }
};

// Time complexity of the code is O(N * K log K), and the space complexity is O(N), 
// where N is the number of strings in the input vector 'strs', and K is the maximum 
// length of a string in 'strs'.