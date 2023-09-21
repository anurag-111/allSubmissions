// https://leetcode.com/problems/partition-string-into-minimum-beautiful-substrings

import java.util.Arrays;

class Solution {
    public int minimumBeautifulSubstrings(String s) {
        int n = s.length();
        int[] dp = new int[n + 1];
        Arrays.fill(dp, n + 1);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            if (s.charAt(i - 1) == '0') {
                continue;
            }

            for (int j = 0; j < i; j++) {
                if (s.charAt(j) == '0') {
                    continue;
                }

                long num = extractNumber(s, j, i);
                if (!isPowerOfFive(num)) {
                    continue;
                }

                dp[i] = Math.min(dp[i], dp[j] + 1);
            }
        }

        return (dp[n] < n + 1) ? dp[n] : -1;
    }

    public long extractNumber(String s, int start, int end) {
        long num = 0;
        for (int i = start; i < end; i++) {
            num = num * 2 + (s.charAt(i) - '0');
        }
        return num;
    }

    public boolean isPowerOfFive(long num) {
        if (num < 125) {
            return (num == 1 || num == 5 || num == 25);
        }

        if (num % 125 != 0) {
            return false;
        } else {
            return isPowerOfFive(num / 125);
        }
    }
}
