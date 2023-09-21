// https://leetcode.com/problems/determine-the-winner-of-a-bowling-game

class Solution {
public:
    int getTurnValue(int x, bool hasStrike[], bool hasSpare[]) {
        if (x == 10 || hasStrike[0] || hasStrike[1] || hasSpare[0] || hasSpare[1]) {
            return 2 * x;
        }
        return x;
    }
    
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int n = player1.size();
        int score1 = 0, score2 = 0;
        bool hasStrike1[2] = {false, false}, hasSpare1[2] = {false, false};
        bool hasStrike2[2] = {false, false}, hasSpare2[2] = {false, false};

        for (int i = 0; i < n; i++) {
            score1 += getTurnValue(player1[i], hasStrike1, hasSpare1);
            score2 += getTurnValue(player2[i], hasStrike2, hasSpare2);

            if (i > 0) {
                if (player1[i - 1] == 10) {
                    hasStrike1[1] = hasStrike1[0];
                    hasStrike1[0] = true;
                }
                else if (player1[i - 1] + player1[i] == 10) {
                    hasSpare1[1] = hasSpare1[0];
                    hasSpare1[0] = true;
                }

                if (player2[i - 1] == 10) {
                    hasStrike2[1] = hasStrike2[0];
                    hasStrike2[0] = true;
                }
                else if (player2[i - 1] + player2[i] == 10) {
                    hasSpare2[1] = hasSpare2[0];
                    hasSpare2[0] = true;
                }
            }
        }

        if (score1 > score2)
            return 1;
        else if (score2 > score1)
            return 2;
        else
            return 0;
        }
};