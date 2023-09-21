// https://leetcode.com/problems/repeated-substring-pattern

class Solution {
    public boolean repeatedSubstringPattern(String s) {
        
        // edge cases
        if(s == null || s.length() == 0) {
            return true;
        }
        
        int size = s.length();

        for(int len = 1; len <= size / 2; len++) {      // pattern must repeat at least twice, i.e. pattern length is at most size / 2
            if(size % len == 0) {             
                String pattern = s.substring(0, len);   // pattern string
                int start = len;                        // start index of 2nd pattern
                int end = start + len - 1;              // end index of 2nd pattern
            
                while(end < size) {
                    String substr = s.substring(start, end + 1);
                    if(!pattern.equals(substr)) {       // failed for this pattern, try next pattern
                        break;
                    } 		
                    start += len;
                    end += len;
                }
                
                if(start == size) {
                    return true;
                }
            }
		}
        return false;
    }
}