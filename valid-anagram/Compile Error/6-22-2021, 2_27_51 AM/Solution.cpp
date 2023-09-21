// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
    
        int f1[26] = {0};
        if(s.length()!=t.length){
            return false;
        }
        else
        {
            for (int i = 0; i < l1; i++)
            {
                f1[s[i] - 'a'] += 1;
                f1[t[i] - 'a'] -= 1;
            }
            for (int i = 0; i < 26; i++)
            {
                if (f1[i] != 0)
                {
                    return false;
                }
            }
            return true;
        }
        
    }
};