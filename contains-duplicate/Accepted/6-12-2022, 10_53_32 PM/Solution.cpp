// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (int x : nums) {
            if(st.find(x) != st.end()){
                return true;
            } else {
                st.insert(x);
            }
        }
        return false;
        
    }
};