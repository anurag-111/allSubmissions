// https://leetcode.com/problems/valid-palindrome

#include <cctype> // For isalnum() and tolower() functions
#include <string>

class Solution {
public:
    // Function to check if a string is a palindrome
    bool isPalindrome(string s) {
        string cleanStr = ""; // String to store the cleaned and normalized version of the input

        // Remove non-alphanumeric characters and convert to lowercase
        for (int i = 0; i < s.size(); i++) {
            if (isalnum(s[i])) {
                cleanStr.push_back(tolower(s[i]));
            }
        }

        // Check if the cleaned string is a palindrome
        for (int i = 0; i < cleanStr.size() / 2; i++) {
            if (cleanStr[i] != cleanStr[cleanStr.size() - i - 1]) {
                return false;
            }
        }

        return true;
    }
};
