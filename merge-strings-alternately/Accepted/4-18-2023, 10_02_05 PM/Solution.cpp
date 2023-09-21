// https://leetcode.com/problems/merge-strings-alternately

class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        int i = 0, j = 0;
        string res = "";

        while (i < w1.size() || j < w2.size()) {
            if (i < w1.size()) {
                res.push_back(w1[i++]);
            }                
            if (j < w2.size()) {
                res.push_back(w2[j++]);
            }                
        }

        return res;
    }
};