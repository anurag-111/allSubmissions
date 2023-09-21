// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> strings;

        for(char str : s) {
            if(isalnum(str)) {
                strings.push_back(tolower(str));
            }
        }

        for(int i = 0; i < strings.size() / 2; i++) {
            if(strings[i] != strings[strings.size() - i - 1]) {
                return false;
            }
        }

        return true;
    }
};