// https://leetcode.com/problems/removing-stars-from-a-string

class Solution {
public:
    string removeStars(string s) {
        string result;
        for(auto itr : s) {
            if(itr == '*') {        // If itr == '*', pop the last element from the stack, to simulate the deletion.
                result.pop_back();
            } else {                // If itr != '*', push the element to the stack.
                result += itr;
            }
        }
        return result;
    }
};