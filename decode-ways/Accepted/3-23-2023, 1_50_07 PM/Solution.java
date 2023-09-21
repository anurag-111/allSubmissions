// https://leetcode.com/problems/decode-ways

class Solution {
    public int numDecodings(String s) {

        int[] dp = new int[s.length()];

        if(s.charAt(0) == '0') {
            dp[0] = 0;
        } else {
            dp[0] = 1;
        }
        
        for (int i = 1; i < dp.length; i++) {            
            if (s.charAt(i - 1) == '0' && s.charAt(i) == '0') {          // Case 1 : Zero , Zero
                dp[i] = 0;
            } else if (s.charAt(i - 1) == '0' && s.charAt(i) != '0') {   // Case 2 : Zero, Non zero
                dp[i] = (i >= 2 ? dp[i - 1] : 0);                        // To prevent index overflow
            } else if (s.charAt(i - 1) != '0' && s.charAt(i) == '0') {   // Case 3 : Non zero, Zero
                if(s.charAt(i - 1) == '1' || s.charAt(i - 1) == '2') {   // So incoming pair deos not exceed 26 : 10, 20. Not valid : 30
                    dp[i] = (i >= 2 ? dp[i - 2] : 1);                    // To prevent index overflow
                } else {
                    dp[i] = 0;
                }
            } else {
                if(Integer.parseInt(s.substring(i - 1, i + 1)) <= 26){   // Case 4 : Non zero, Non zero
                    dp[i] = dp[i - 1] + (i >= 2 ? dp[i - 2] : 1);        // To prevent index overflow
                } else {
                    dp[i] = dp[i - 1];
                }
            }
        }

        return dp[s.length() - 1];
    }
}