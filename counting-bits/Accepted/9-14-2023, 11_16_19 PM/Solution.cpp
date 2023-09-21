// https://leetcode.com/problems/counting-bits

class Solution {
private:
    int countSetBits(int number) {
        int count = 0;
        while(number) {
            number = number & (number - 1);
            count++;
        }
        return count;
    }

public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1);

        for(int i = 0; i < result.size(); i++) {
            result[i] = countSetBits(i);
        }

        return result;
    }
};