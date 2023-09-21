// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int product = 1;
        vector <int> result;
        
        //Traverse from left to right
        for( int i = 0; i < n; i++) {
            product *= nums[i];
            result.push_back(product);
        }
        
        // for (int i = 0; i < n; i++)
        //     cout << result[i] << " ";
        
        product = 1;
        
        //Traverse from right to left and update.
        for(int i = n - 1; i > 0; i--) {
            result[i] = result[i - 1] * product;
            product *= nums[i];
        }
        
        result[0] = product;
        return result;
    }
};