// https://leetcode.com/problems/reverse-string

class Solution {
public:
    // Function to reverse a vector of characters in place.
    void reverseString(vector<char>& charVector) {
        int leftIndex = 0;
        int rightIndex = charVector.size() - 1;

        // Swap characters from the left and right ends of the vector until they meet in the middle.
        while (leftIndex < rightIndex) {
            char tempChar = charVector[leftIndex];
            charVector[leftIndex] = charVector[rightIndex];
            charVector[rightIndex] = tempChar;

            // Move to the next characters from both ends.
            leftIndex++;
            rightIndex--;
        }
    }
};
