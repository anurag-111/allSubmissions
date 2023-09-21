// https://leetcode.com/problems/valid-parenthesis-string

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open; // Stack to store indices of '(' characters
        stack<int> star; // Stack to store indices of '*' characters

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open.push(i); // Push the index of '(' character to the stack
            } else if (s[i] == '*') {
                star.push(i); // Push the index of '*' character to the stack
            } else {
                if (!open.empty()) {
                    open.pop(); // Match ')' with '(' from the stack
                } else if (!star.empty()) {
                    star.pop(); // Use '*' to match ')' if '(' is not available
                } else {
                    return false; // No valid matching for ')'
                }
            }
        }

        while (!open.empty()) {
            if (star.empty()) {
                return false; // '(' is not matched by '*' or ')'
            } else if (open.top() < star.top()) {
                open.pop(); // Match remaining '(' with '*' from the stack
                star.pop();
            } else {
                return false; // '(' is not matched by '*' or ')'
            }
        }

        return true; // All '(' are matched
    }
};

// Approach :
// Iterate through the input string s and use two stacks, open and star, 
// to keep track of the indices of opening parentheses '(' and asterisks '*' encountered.

// Time Complexity : 
// The time complexity of this approach is O(n), where n is the length of the input string s. 
// This is because we iterate through s once, performing constant-time operations for each character.

// Space Complexity : 
// The space complexity is O(n) as well. In the worst case, all characters in s could be opening 
// parentheses or asterisks, and both stacks open and star could contain up to n elements.