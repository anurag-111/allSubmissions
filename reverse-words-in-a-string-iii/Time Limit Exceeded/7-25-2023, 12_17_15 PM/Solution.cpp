// https://leetcode.com/problems/reverse-words-in-a-string-iii

class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int end = 0;
        string result;
        int size = s.size();

        while(start < size) {
            // For leading spaces
            while(start < size && s[start] == ' ') {
                start++;
            }

            // Set end as start and then traverse to find the word chunk
            while(end < size && s[end] != ' ') {
                end++;
            }

            // Now we will select the word chunk
            string word = s.substr(start, end - start);

            // Now reverse that particular word chunk
            reverse(s.begin(), s.end());

            // Append this reversed word into our result
            result += word;
        }

        // Return the result
        return result;
    }
};