// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> dig;

        if((x < 0) || (x != 0 && x % 10 == 0)) {
            return false;
        } 

        while(x) {
            int new_num = x % 10;
            dig.push_back(new_num);
            x = x / 10;
        }

        for(int i = 0; i < dig.size() / 2; i++) {
            if(dig[i] != dig[dig.size() - i - 1]) {
                return false;
            }
        }
        
        return true;
    }
};