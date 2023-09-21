// https://leetcode.com/problems/scramble-string

//Memoization Approach
class Solution {
    unordered_map<string, bool> mem;

    bool solve(string s1,string s2) {
        if(s1.size() == 1) {
            return s1 == s2;
        }
            
        if(s1 == s2) {
            return true;
        }
            
        string key = s1 + s2;

        if(mem.find(key) != mem.end()) {
            return mem[key];
        }            
        
        int n = s1.size();
        bool res = false;

        for(int i = 1; i < n; ++i) {
            if((solve(s1.substr(0, i), s2.substr(0, i)) && solve(s1.substr(i), s2.substr(i))) || 
                (solve(s1.substr(0, i), s2.substr(n - i)) && solve(s1.substr(i), s2.substr(0, n - i)))) {
                    return mem[key] = true;
            }
                
        }

        return mem[key] = false;
    }

public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        return solve(s1,s2);
    }
};