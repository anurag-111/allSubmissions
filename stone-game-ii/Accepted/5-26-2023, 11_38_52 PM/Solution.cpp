// https://leetcode.com/problems/stone-game-ii

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        if (piles.empty()) return 0;

        vector<int> sums(piles.size() + 1, 0);
        for (int i = piles.size() - 1; i >= 0; --i)
            sums[i] = sums[i + 1] + piles[i];

        vector<vector<int>> dp(piles.size(), vector<int>(piles.size() + 1, 0));
        return helper(piles, dp, sums, 0, 1);
    }

    int helper(vector<int>& piles, vector<vector<int>>& dp, vector<int>& sums, int i, int M) {
        if (i == piles.size()) return 0;
        if (2 * M >= piles.size() - i) return sums[i];

        if (dp[i][M]) return dp[i][M];

        int minimum = INT_MAX;
        for (int j = 1; j <= 2 * M; ++j)
            minimum = min(minimum, helper(piles, dp, sums, i + j, max(j, M)));

        return dp[i][M] = sums[i] - minimum;
    }
};
