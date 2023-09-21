// https://leetcode.com/problems/number-of-1-bits

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // Input is in integer and not in 0's and 1's.
        int count = 0;
        while(n) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};

// 23 & 22, which is 10111 & 10110 -> 10110
// 22 & 21, which is 10110 & 10101 -> 10100
// 20 & 19, which is 10100 & 10011 -> 10000
// 16 & 15, which is 10000 & 01111 -> 00000
