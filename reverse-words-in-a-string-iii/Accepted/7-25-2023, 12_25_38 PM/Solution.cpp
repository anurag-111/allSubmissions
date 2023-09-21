// https://leetcode.com/problems/reverse-words-in-a-string-iii


class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int end = 0;
        string result;
        int size = s.size();

        // Traverse the input string to reverse each word
        while (start < size) {
            // Skip leading spaces
            while (start < size && s[start] == ' ') {
                start++;
            }

            // Set end as start and then traverse to find the word chunk
            end = start;
            while (end < size && s[end] != ' ') {
                end++;
            }

            // Extract the current word
            string word = s.substr(start, end - start);

            // Reverse the current word
            reverse(word.begin(), word.end());

            // Append the reversed word to the result
            result += word;

            // Append a space after each word (except the last one)
            if (end < size) {
                result += ' ';
            }

            // Move to the next word
            start = end + 1;
        }

        // Return the result
        return result;
    }
};