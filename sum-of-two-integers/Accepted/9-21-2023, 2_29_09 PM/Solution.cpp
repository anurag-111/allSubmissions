// https://leetcode.com/problems/sum-of-two-integers

class Solution {
public:
    int getSum(int a, int b) {
        if(b == 0) {
            return a;
        }
        
        int sumWithoutCarry = a ^ b;
        int carry = (a & b) << 1;
        
        return getSum(sumWithoutCarry, carry);
    }
};