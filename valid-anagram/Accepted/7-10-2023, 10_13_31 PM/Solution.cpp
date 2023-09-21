// https://leetcode.com/problems/valid-anagram

#include <unordered_map>

class Solution {
public:
    // Function to check if two strings are anagrams
    bool isAnagram(string s, string t) {
        // If the lengths of the strings are different, they cannot be anagrams
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> count; // Map to store character counts

        // Count the frequency of each character in the strings
        for (int i = 0; i < s.size(); i++) {
            count[s[i]]++; // Increment count for character in string s
            count[t[i]]--; // Decrement count for character in string t
        }

        // Check if all counts are zero
        for (const auto& pair : count) {
            if (pair.second != 0) {
                return false; // If any count is non-zero, strings are not anagrams
            }
        }

        return true; // All counts are zero, strings are anagrams
    }
};
