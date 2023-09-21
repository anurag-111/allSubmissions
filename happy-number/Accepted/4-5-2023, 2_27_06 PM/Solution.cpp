// https://leetcode.com/problems/happy-number

class Solution {
private:
    int next_number(int n) {
        long new_num = 0;
        while(n) {
            int num = n % 10;
            new_num +=  num * num;
            n = n/10;
        }
        return new_num;
    }
    
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while(n != 1 && (set.count(n) == 0)) {
            set.insert(n);
            n = next_number(n);
        }
        return n == 1;
    }
};

