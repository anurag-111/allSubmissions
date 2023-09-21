// https://leetcode.com/problems/decode-ways-ii

class Solution {
        public int numDecodings(String s) {
        
        long[] dp = new long[s.length() + 1];
        dp[0] = 1;

        if(s.charAt(0) == '0'){
            return 0;
        }

        dp[1] = (s.charAt(0) == '*') ? 9 : 1;

        
        for(int i = 2; i <= s.length(); i++){
            
            char first = s.charAt(i - 2);
            char second = s.charAt(i - 1);

            // For dp[i-1]
            if(second == '*') {
                dp[i] += 9 * dp[i - 1];             
            }else if(second > '0') {
                dp[i] += dp[i - 1];
            }
            
            // For dp[i-2]
            if(first == '*') {
                if(second == '*') {
                    dp[i] += 15 * dp[i - 2];        // Valid combinations if * and *
                }else if(second <= '6') {
                    dp[i] += 2 * dp[i - 2];         // Valid combinations if * and {1,2,3,4,5,6}
                }else{
                    dp[i] += dp[i - 2];
                }
            }else if(first == '1' || first == '2') {  
                if(second == '*') {                 // Valid combinations if (1, 2) and *
                    if(first == '1') {
                       dp[i] += 9 * dp[i - 2]; 
                    }else { // first == '2'
                       dp[i] += 6 * dp[i-2]; 
                    }
                }else if( ((first - '0') * 10 + (second - '0')) <= 26 ){         
                    dp[i] += dp[i - 2];    
                }
            }

            dp[i] %= 1e9 + 7;
        }
        
        return (int)dp[s.length()];
    }
}