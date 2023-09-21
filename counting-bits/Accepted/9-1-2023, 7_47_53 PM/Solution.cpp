// https://leetcode.com/problems/counting-bits

class Solution {
private:
    int calculateSetBits(int number) {
        int count = 0;
        while (number) {
            count += number & 1;
            number >>= 1;
        }
        return count;
    }

public:
    vector<int> countBits(int n) {
        vector<int> answer(n + 1);

        for (int i = 0; i <= n; i++) {
            answer[i] = calculateSetBits(i);
        }

        return answer;
    }
};
