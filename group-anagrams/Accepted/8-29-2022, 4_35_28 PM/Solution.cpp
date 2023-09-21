// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs){
            mp[mySort(s)].push_back(s);                        
        }
        vector<vector<string>> anagrams;
        for (auto itr : mp){
            anagrams.push_back(itr.second);
        }
        return anagrams;
        
    }
private:
    string mySort(string s){
        int counter[26] = {0};
        for (char c : s){
            counter [c - 'a']++;
        }
        string key;
        for(int c = 0; c < 26; c++){
            key += string(counter[c], c + 'a');
        }
        return key;
    }
};