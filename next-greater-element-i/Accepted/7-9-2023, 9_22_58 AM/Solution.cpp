// https://leetcode.com/problems/next-greater-element-i

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size(), -1);
        vector<int> nextGreater(10001, -1);
        stack<int> st;

        for(auto num : nums2) {
            while(!st.empty() && st.top() < num) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        for(int i = 0; i < nums1.size();i++) {
            result[i] = nextGreater[nums1[i]];
        }

        return result;
    }
};