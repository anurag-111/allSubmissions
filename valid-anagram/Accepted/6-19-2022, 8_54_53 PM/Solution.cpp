// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
    
        int counts[26] = {0};

        if (s.length() != t.length()) {
            return false;
        }

        for (int i = 0; i < s.size(); i++) {
            counts[s[i] - 'a']++; //when s[i] = 'a', index = 0
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (counts[i] != 0) {
                return false;
            }
        }
        return true;
    }
};