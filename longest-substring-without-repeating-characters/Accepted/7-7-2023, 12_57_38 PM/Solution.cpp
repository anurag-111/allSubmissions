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
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        
        unordered_map<char, int> charIndexMap; // Map to store the most recent index of each character
        
        int start = 0; // Start index of the current substring
        int maxLen = 0; // Length of the longest substring without repeating characters

        for (int end = 0; end < s.size(); end++) {
            char currentChar = s[end];

            // If the current character is already found in the substring
            if (charIndexMap.count(currentChar)) {
                start = max(start, charIndexMap[currentChar] + 1); // Update the start index to skip the repeated character
            }

            maxLen = max(maxLen, end - start + 1); // Update the maximum length if necessary
            charIndexMap[currentChar] = end; // Update the most recent index of the current character
        }
        
        return maxLen;
    }
};

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