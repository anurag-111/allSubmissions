// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> validChars;

        // Collect valid alphanumeric characters
        for (char c : s) {
            if (isalnum(c)) {
                validChars.push_back(tolower(c));
            }
        }

        int left = 0;
        int right = validChars.size() - 1;

        // Check if the valid characters form a palindrome
        while (left < right) {
            if (validChars[left] != validChars[right]) {
                return false;  // Not a palindrome
            }
            left++;
            right--;
        }

        return true;  // Palindrome
    }
};
