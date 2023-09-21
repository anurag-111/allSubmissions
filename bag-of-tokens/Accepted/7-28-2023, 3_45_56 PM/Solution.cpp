// https://leetcode.com/problems/bag-of-tokens

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(!tokens.size()) {
            return 0;
        }

        int score = 0;
        int left = 0;
        int maxScore = 0;
        int right = tokens.size() - 1;

        sort(tokens.begin(), tokens.end());

        while(left <= right) {
            if(power >= tokens[left]) {
                // face up operation
                power -= tokens[left];
                score++;
                maxScore = max(maxScore, score);
                left++;
            } else if(score > 0) {
                // face down opeation
                power += tokens[right];
                score--;
                right--;
            } else  {
                break;
            }
        }

        return maxScore;
    }
};