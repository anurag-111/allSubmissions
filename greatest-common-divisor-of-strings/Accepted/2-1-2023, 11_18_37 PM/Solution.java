// https://leetcode.com/problems/greatest-common-divisor-of-strings

class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if(!(str1+str2).equals(str2+str1)) {
            return "";
        }
        int gcd = getGcd(str1.length(), str2.length());
        return str1.substring(0, gcd);
    }

    public int getGcd(int a, int b) {
        if (b==0) {
            return a;
        }
        return getGcd(b, a % b);
    }
}
/* 
    Time Complexity: O(N)
        GCD calculates in O(log N) time.
        String iteration and equals checking takes O(N+M) time.
    
    Space Complexity : O(N + M)
 */

