// https://leetcode.com/problems/number-of-senior-citizens

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int countSeniors = 0;
        for(auto detail : details) {
            int age = (detail[11] - '0') * 10 + (detail[12] - '0');
            if(age > 60) {
                countSeniors++;
            }
        }
        return countSeniors;
    }
};