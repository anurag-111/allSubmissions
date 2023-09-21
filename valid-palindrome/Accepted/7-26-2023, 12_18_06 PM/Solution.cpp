// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> cleanPhrase; 
        
        // Extract alphanumeric characters and convert to lowercase
        for (int i = 0; i < s.size(); i++) {
            if (isalnum(s[i])) {
                cleanPhrase.push_back(tolower(s[i])); 
            }
        }
        
        int left = 0, right = cleanPhrase.size() - 1;
        while (left < right) {
            if (cleanPhrase[left] != cleanPhrase[right]) {
                return false; // If characters don't match, it's not a palindrome
            }
            left++;
            right--;
        }
        
        return true; // If the loop finishes, the phrase is a palindrome
    }
};