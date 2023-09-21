// https://leetcode.com/problems/power-of-two

class Solution {
public:
    bool isPowerOfTwo(int n) {
       if(n == 1) {
           return true;
       } else if(n & 1) {
           return false;
       } else {
           return true;
       }
    }
};

