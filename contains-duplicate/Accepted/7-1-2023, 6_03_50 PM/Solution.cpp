// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int num : nums) {
            if(st.find(num) == st.end()) {
                st.insert(num);
            } else {
                return true;
            }
        }
        return false;
    }
};