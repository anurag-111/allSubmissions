// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) {
        int needleSize = needle.size();
        int haystackSize = haystack.size();

        for(int i = 0; i < haystackSize; i++) {
            if(haystack.substr(i, needleSize) == needle) {
                cout << haystack.substr(i, needleSize);
                return i;
            }
        }
        return -1;
    }
};