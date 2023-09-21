// https://leetcode.com/problems/find-smallest-letter-greater-than-target

class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int n = letters.length;
       
        // Check if target is greater than or equal to the last element
        // If true, wrap around and return the first element
        if (target >= letters[n - 1]) {
            target = letters[0];
        } else {
            // Increment the target to find the next greatest letter
            target++;
        }
        
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (letters[mid] == target) {
                return letters[mid];
            }
            if (letters[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        // Return the element at high index as it is the next greatest letter
        return letters[high];
    }
}
