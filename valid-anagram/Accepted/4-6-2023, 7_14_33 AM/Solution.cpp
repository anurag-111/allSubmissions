// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> counts(26, 0);

        if (s.length() != t.length()) {
            return false;
        }

        for(int i = 0; i < s.length(); i++) {
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }

        for(int i = 0; i < counts.size(); i++) {
            if(counts[i]){
                return false;
            }
        }

        return true;
    }
};