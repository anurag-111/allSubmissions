// https://leetcode.com/problems/edit-distance

class Solution {
    public int minDistance(String word1, String word2) {
        
        int m = word1.length();
        int n = word2.length();
        
        int[][] ed = new int[m + 1][n + 1];
        
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                
                if (i == 0 && j == 0) {
                    ed[i][j] = 0;
                } else if (i == 0) {
                    ed[i][j] = 1 + ed[i][j - 1];
                } else if (j == 0) {
                    ed[i][j] = 1 + ed[i - 1][j];
                } else {
                    if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                        ed[i][j] = ed[i - 1][j - 1];
                    } else {
                        ed[i][j] = 1 + Math.min(ed[i - 1][j], Math.min(ed[i - 1][j - 1],
                                                                       ed[i][j - 1]));
                    }
                }
            }
        }
        
        return ed[m][n];
    }
}