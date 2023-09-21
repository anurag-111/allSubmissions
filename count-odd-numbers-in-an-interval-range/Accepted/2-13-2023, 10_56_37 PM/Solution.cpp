// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range

class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;
        for(int num = low; num <= high; num++) {
            if(num % 2 != 0) {
                count++;
            } 
        }
        return count;
    }
};