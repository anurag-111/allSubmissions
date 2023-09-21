// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> from_begin(n);
        vector <int> from_end(n);
        from_begin[0] = 1;
        from_end[0] = 1;
        for(int i = 1; i<n ;i++){
            from_begin[i] = from_begin[i-1] * nums[i-1];
            fromLast[i]=fromLast[i-1]*nums[n-i];
        }
        vector<int> res(n);
        for(int i=0;i<n;i++){
            res[i]=fromBegin[i]*fromLast[n-1-i];
        }
        return res;
    }
};