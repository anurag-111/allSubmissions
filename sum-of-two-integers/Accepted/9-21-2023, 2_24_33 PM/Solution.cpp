// https://leetcode.com/problems/sum-of-two-integers

class Solution {
public:
    int getSum(int a, int b) {
    // Base case: if b is 0, return a (no more additions to perform)
    if (b == 0) {
        return a;
    }
    
    // Add the digits without carrying, and store the carry in b
    int sumWithoutCarry = a ^ b;
    
    // Calculate the carry and prepare for the next addition
    int carry = (a & b) << 1;
    
    // Recursively call getSum with the updated values
    return getSum(sumWithoutCarry, carry);
}

};