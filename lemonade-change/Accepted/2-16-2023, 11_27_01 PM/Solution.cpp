// https://leetcode.com/problems/lemonade-change

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5 = 0;
        int count10 = 0;
        for (int bill : bills) {
            if (bill == 5) {
                count5++;
            } else if (bill == 10) {
                count5--;
                count10++;
            } else {                    // bills[i] = 20
                if (count10 >= 1) {
                    count10--;
                    count5--;
                } else {
                    count5 -= 3;
                }
            } 
            cout<<count5;
            if (count5 < 0) {           // for test cases such as : [5,5,10,10,20]
                return false;
            }
        }
        return true;
    }
};