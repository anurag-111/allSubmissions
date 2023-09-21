// https://leetcode.com/problems/bulb-switcher-ii

class Solution {
    public :
    int flipLights(int n, int m) {
        if (m == 0 || n == 0) {   
            // If m or n is zero, the function returns 1 because there is only one possible configuration.
            return 1;
        } else if (n == 1) {     
            // If n is 1, the function returns 2 because there are only 
            // two possible configurations (on or off).
            return 2;     
        } else if (n == 2) {      
            if (m == 1) {
                // If n is 2 and m is 1, the function returns 3 because there are three possible 
                // configurations (both lights on, both lights off, or one light on and the other off)
                return 3;
            } else {
                // If n is 2 and m is greater than 1, the function returns 4 because there are 
                // four possible configurations (both lights on, both lights off, one light on 
                // and the other off, or both lights with opposite states).
                return 4;
            }
        } else if (m == 1) {
            // If m is 1 and n is greater than 2, the function returns 4 because there are four 
            // possible configurations that can be produced by flipping one light. 
            return 4;
        } else if (m == 2) {
            // If m is 2 and n is greater than 2, the function returns 7 because there are 
            // seven possible configurations that can be produced by flipping two lights.
            return 7;
        } else {
            // If m is greater than 2 and n is greater than 2, the function returns 8 
            // because there are eight possible configurations that can be produced by flipping three or more lights.
            return 8;
        }
    }
};