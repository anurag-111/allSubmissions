// https://leetcode.com/problems/optimal-partition-of-string

class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> str;
        int count = 1;
        for(int i = 0; i < s.size(); i++) {
            if(str.find(s[i]) != str.end()) {
                count++;
                str.clear();
            }
            str.insert(s[i]);
        }
        return count;
    }
};