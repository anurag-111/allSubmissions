// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
    
    int l1 = s.length();
    int l2 = t.length();
    int f1[26], f2[26],flag=1;
        
        if(l1!=l2){
            return false;
        }
    
        else
        {
            for (int i = 0; i < 26; i++){
                f1[i] = 0;
                f2[i] = 0;
            }
            for (int i = 0; i < l1; i++){
                f1[s[i] - 'a'] += 1;
                f2[t[i] - 'a'] += 1;
            }
            for (int i = 0; i < 26; i++){
                if (f1[i] != f2[i])
                    return false;
                
            }    
        }
        return true;
    }
};