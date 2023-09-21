// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends

class Solution {
public:
    int minimumLength(string s) {
        // Initialize left and right pointers to the beginning and end of the string.
        int left = 0;
        int right = s.size() - 1;
        
        // Loop until left pointer is less than right pointer.
        while (left < right) {
            // Move left pointer while adjacent characters are the same.
            while (left < right && s[left] == s[left + 1]) {
                left++;
            }
            
            // Move right pointer while adjacent characters are the same.
            while (right > left && s[right] == s[right - 1]) {
                right--;
            }
            
            // Check if characters at left and right pointers are not the same or
            // if the left pointer has surpassed the right pointer. In either case, break the loop.
            if (s[left] != s[right] || left >= right) {
                break;
            }
            
            // If the characters at left and right pointers are the same,
            // move both pointers towards the center.
            left++;
            right--;
        }
        
        // The minimum length of the remaining substring is the difference between
        // right and left pointers plus 1 (to include the characters at both pointers).
        return (right - left + 1);
    }
};


// Time complexity: O(n)

// The code iterates through the string with two pointers, left and right.
// In the worst case, the code may need to check all characters in the string once, 
// resulting in a linear time complexity.
    
// Space complexity: O(1)

// The code uses only a constant amount of extra space regardless of the input string's size.
// The space required for variables (left, right, s.size(), etc.) remains constant as the input grows.
// Hence, the space complexity is constant or O(1).