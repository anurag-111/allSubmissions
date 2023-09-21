// https://leetcode.com/problems/next-greater-element-i

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> nextGreater(10001, -1);
        vector<int> result(nums1.size());
        
        for(int i = 0; i < nums2.size(); i++) {
            while(!st.empty() && st.top() < nums2[i]) {
                nextGreater[st.top()] = nums2[i];
                st.pop();
            } 
            st.push(nums2[i]);
        }
        
        
        for(int i = 0; i < result.size(); i++) {
            result[i] = nextGreater[nums1[i]];
        }
        
        return result;
    }
};