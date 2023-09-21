// https://leetcode.com/problems/permutation-in-string

class Solution {
public:
    void checker(int check[26]) {
        for (int c : check) {
            if (c != 0) {
                match = false;
                break;
            }
        }
    }
    
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        
        int count[26] = {0};
        int start = 0;
        
        for (char c : s1) {
            count[c - 'a']++;
        }
        
        for (int i = 0;i < s1.size(); i++) {
            count[s2[i] - 'a']--;
        }
        
        bool match = true;
        match = checker(count);
        if (match) {
            return true;
        }
        start++;
        
        while (start <= s2.length() - s1.length()) {
            int index1 = s2[start-1] - 'a';
            int index2 = s2[start + s1.length() - 1] - 'a';
            count[index]++;
            count[index]--;
            match = true;
            match = checker(count);
            if (match) {
                return true;
            }
            start++;
        }
        return false;        
    }
};