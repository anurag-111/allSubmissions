// https://leetcode.com/problems/di-string-match

class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> result(s.size() + 1);
        int low = 0;
        int size = s.size();
        int high = size;
        int index = 0;

        for(int i = 0; i < size; i++) {
            if(s[i] == 'I') {
                result[index++] = low++;
            } else {
                result[index++] = high--;
            }
        }

        result[size] = high;
        return result;
    }
};