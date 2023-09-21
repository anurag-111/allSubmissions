// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.length() - 1;
        int val = 0;
        while (end >= 0 && s[end] == ' ') {
            end--;
        }
        while (end >= 0 && s[end] != ' ') {
            val++;
            end--;
        }
        return val;
    }
};

//Start from the end of s and move backwards to find the first non-space character. 
//Then from this character, move backwards and count the number of non-space characters 
//until we pass over the head of s or meet a space character. 
//The count will then be the length of the last word.