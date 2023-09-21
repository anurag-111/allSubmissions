// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size()) {
            return 0;
        }
        
        unordered_map<char, int> indexForChar;
        
        int start = 0;
        int maxLen = 0;

        for(int end = 0; end < s.size(); end++) {
            char currentChar = s[end];

            //if found
            if(indexForChar.count(currentChar)) {
                start = max(start, indexForChar[currentChar] + 1);
            }

            maxLen = max(maxLen, end - start + 1);
            indexForChar[currentChar] = end;
            
        }
        return maxLen;
    }
};