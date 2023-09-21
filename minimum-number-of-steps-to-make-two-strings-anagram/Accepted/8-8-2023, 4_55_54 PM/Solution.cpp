// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram

class Solution {
public:
    int minSteps(string s, string t) {
        int charCount[26];
        int count = 0;

        // A frequency count initialised with 0
        for(int i = 0; i < 26; i++) {
            charCount[i] = 0;
        }

        // Traverse over the string 1 and update the count
        for(int i = 0; i < s.size(); i++) {
            charCount[s[i] - 'a']++;
        }

        // Traverse over the string 2 and update the count
        for(int i = 0; i < t.size(); i++) {
            charCount[t[i] - 'a']--;
        }

        // Count the differences
        for(int i = 0; i < 26; i++) {
            count += abs(charCount[i]);
        }

        // Since we've counted the manipulations twice (once for each string), 
        // we divide the count by 2 to get the actual number of manipulations 
        // needed to make the two strings identical.
        return count / 2;
    }
};

// Time complexity : O(N)
// Space complexity : O(1)