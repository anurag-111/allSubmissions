// https://leetcode.com/problems/determine-the-winner-of-a-bowling-game

class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int score1 = 0, score2 = 0;
        int cur1 = 0, cur2 = 0, prev1 = 0, prev2 = 0;

        for (int i = 0; i < player1.size(); i++) {
            // player 1 turn
            cur1 = player1[i];
            prev1 = i >= 1 ? player1[i-1] : 0;
            prev2 = i >= 2 ? player1[i-2] : 0;

            if (cur1 == 10) {
                score1 += cur1;
            } else if (prev1 == 10 || prev2 == 10) {
                score1 += 2 * cur1;
            } else {
                score1 += cur1;
            }

            // player 2 turn
            cur2 = player2[i];
            prev1 = i >= 1 ? player2[i-1] : 0;
            prev2 = i >= 2 ? player2[i-2] : 0;

            if (cur2 == 10) {
                score2 += cur2;
            } else if (prev1 == 10 || prev2 == 10) {
                score2 += 2 * cur2;
            } else {
                score2 += cur2;
            }
        }

        if (score1 > score2) {
            return 1;
        } else if (score2 > score1) {
            return 2;
        } else {
            return 0;
        }

    }
};