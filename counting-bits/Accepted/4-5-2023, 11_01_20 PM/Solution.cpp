// https://leetcode.com/problems/counting-bits

class Solution {
private:
    int find(int num) {
        int count = 0;
        while(num) {
            int new_num = num % 2;
            if(new_num == 1) {
                count++;
            }
            num = num / 2;
        }
        return count;
    }

public:
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i = 0; i <= n; i++) {
            int current = i;
            // Find the occurence of 1 in our binary representation of the current number
            int current_count = find(current);
            result.push_back(current_count);
        }
        return result;
    }
};