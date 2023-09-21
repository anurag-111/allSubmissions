// https://leetcode.com/problems/sign-of-the-product-of-an-array

class Solution {
private: 
    int signFunc(int x) {
        if(x > 0) {
            return 1;
        } else if(x < 0) {
            return -1;
        } else {
            return 0;
        }
    }
public:
    int arraySign(vector<int>& nums) {
        int product = 1;
        for(int i = 0; i < nums.size(); i++) {
            product = product * nums[i];
        }
        return signFunc(product);
    }
    
};