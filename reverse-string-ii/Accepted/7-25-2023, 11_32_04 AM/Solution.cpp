// https://leetcode.com/problems/reverse-string-ii

class Solution {
public: 
    string reverseStr(string s, int k) {
        int size = s.size();

        // Iterate through the string in chunks of size 2*k
        for (int i = 0; i < size; i += 2 * k) {
            // Determine the boundaries of the current chunk
            int start = i;
            int end = min(i + k, size);

            // Reverse the characters in the current chunk
            reverse(s.begin() + start, s.begin() + end);
        }

        return s;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)