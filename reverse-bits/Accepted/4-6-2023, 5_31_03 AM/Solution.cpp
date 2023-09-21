// https://leetcode.com/problems/reverse-bits

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int result = 0;
        for(int i = 0; i < 32; i++) {
            // Calculate the Least Significant Bit
            int lsb = n & 1;
            // Now to reverse the bits:
            int reverse = lsb << (31 - i);
            result = result | reverse;
            // Right shift the original number
            n = n >> 1;
        }
        return result;
    }
};