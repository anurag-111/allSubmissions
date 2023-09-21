// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    // Function to check if two strings are anagrams
    bool isAnagram(string s, string t) {
        // If the lengths of the strings are different, they cannot be anagrams
        if (s.size() != t.size()) {
            return false;
        }

        vector<int> count(26, 0); // Array to store character counts

        // Count the frequency of each character in the strings
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++; // Increment count for character in string s
            count[t[i] - 'a']--; // Decrement count for character in string t
        }

        // Check if all counts are zero
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false; // If any count is non-zero, strings are not anagrams
            }
        }

        return true; // All counts are zero, strings are anagrams
    }
};