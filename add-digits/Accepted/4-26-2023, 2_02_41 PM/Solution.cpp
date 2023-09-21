// https://leetcode.com/problems/add-digits

class Solution {
public:
    int addDigits(int num) {
        if(num == 0) {
            return 0;
        } else if(num % 9 == 0) {
            return 9;
        } else {
            return num % 9;
        }
    }
};

// O(1) Approach :
    // This approach is based on the mathematical property that 
    // the digital root of a number is equivalent to the number modulo 9, 
    // except when the number is itself a multiple of 9. This property 
    // allows the code to compute the digital root of a number in constant 
    // time, without actually summing its digits. It also avoids potential 
    // integer overflow issues that could occur when summing large numbers 
    // with multiple digits.