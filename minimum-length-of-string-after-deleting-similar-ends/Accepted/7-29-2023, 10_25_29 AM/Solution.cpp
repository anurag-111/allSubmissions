// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends

class Solution {
public:
    int minimumLength(string s) {
        int left = 0;                      // Pointer to the leftmost character.
        int right = s.size() - 1;          // Pointer to the rightmost character.
        
        // Continue iterating until left pointer is less than right pointer
        // and the characters at the corresponding positions are the same.
        while (left < right && s[left] == s[right]) {
            char commonChar = s[left];     // Store the character at the current left pointer position
            
            // Move left pointer towards the right while adjacent characters are the same.
            while (left <= right && s[left] == commonChar) {
                left++;
            }
            
            // Move right pointer towards the left while adjacent characters are the same.
            while (right >= left && s[right] == commonChar) {
                right--;
            }
        }
        
        // The minimum length of the remaining substring is the difference between
        // right and left pointers plus 1 (to include the characters at both pointers).
        return (right - left + 1);
    }
};

// TC : O(N)
// SC : O(1)