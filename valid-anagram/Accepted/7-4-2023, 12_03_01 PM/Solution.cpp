// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }

        unordered_map<int, int> sMap;
        unordered_map<int, int> tMap;

        for(int i = 0; i < s.size(); i++) {
            sMap[s[i]]++;
        }

        for(int i = 0; i < t.size(); i++) {
            tMap[t[i]]++;
        }

        for(int i = 0; i < s.size(); i++) {
            if(sMap[s[i]] != tMap[s[i]]) {
                return false;
            } 
        }
        return true;
    }
};