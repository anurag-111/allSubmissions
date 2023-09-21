// https://leetcode.com/problems/number-of-1-bits

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while(n) {
            int new_num = n %  2;
            if(new_num == 1) {
                count++;
            }            
            n = n / 2;
        }

        return count;
    }
};