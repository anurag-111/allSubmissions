// https://leetcode.com/problems/add-digits

class Solution {
private:
    int addSum(int n) {
        int newNum;
        int sum = 0;
        while(n) {
            newNum = n % 10;
            sum += newNum;
            n /= 10;
        }
        return sum;
    }
public:
    int addDigits(int num) {
        int newSum = addSum(num);
        while(!((newSum / 10) < 1)) {
            newSum = addSum(newSum);
        }
        return newSum;
    }
};