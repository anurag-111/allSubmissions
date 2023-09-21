// https://leetcode.com/problems/bag-of-tokens

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // If tokens are empty, return 0
        if (tokens.empty()) {
            return 0;
        }

        // Initialize variables
        int score = 0;                  // Current score
        int left = 0;                   // Index of the leftmost token
        int maxScore = 0;               // Maximum score achieved
        int right = tokens.size() - 1;  // Index of the rightmost token

        // Sort tokens for efficient operations
        sort(tokens.begin(), tokens.end());

        // Loop until left and right indices meet
        while (left <= right) {
            if (power >= tokens[left]) {
                // Face up operation
                power -= tokens[left];
                score++;
                maxScore = max(maxScore, score);
                left++;
            } else if (score > 0) {
                // Face down operation
                power += tokens[right];
                score--;
                right--;
            } else {
                // No more available moves, break the loop
                break;
            }
        }

        return maxScore;
    }
};
