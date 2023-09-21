// https://leetcode.com/problems/di-string-match

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();  // Length of the input string
        vector<int> result(n + 1);  // To store the resulting sequence
        
        int low = 0;  // Initialize the value for ascending order
        int high = n;  // Initialize the value for descending order
        int index = 0;  // Initialize the index to fill in the result vector
        
        for (int i = 0; i < n; i++) {
            if (s[i] == 'I') {
                result[index++] = low++;  // Place the ascending value and increment it
            } else {
                result[index++] = high--;  // Place the descending value and decrement it
            }
        }

        result[n] = high;  // Place the remaining value at the end (low or high)
        return result;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)