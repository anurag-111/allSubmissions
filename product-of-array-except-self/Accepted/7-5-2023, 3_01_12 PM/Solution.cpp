// https://leetcode.com/problems/product-of-array-except-self

#include <vector>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();

        // Initialize vectors to store the products
        vector<int> preProduct(size, 1);    // Stores products of elements before the current index
        vector<int> postProduct(size, 1);   // Stores products of elements after the current index
        vector<int> result(size, 0);        // Stores the final result

        // Calculate products of elements before the current index
        for (int i = 1; i < size; i++) {
            preProduct[i] = preProduct[i - 1] * nums[i - 1];
        }

        // Calculate products of elements after the current index
        for (int i = size - 2; i >= 0; i--) {
            postProduct[i] = postProduct[i + 1] * nums[i + 1];
        }

        // Calculate the final result by multiplying the preProduct and postProduct
        for (int i = 0; i < size; i++) {
            result[i] = preProduct[i] * postProduct[i];
        }

        return result;
    }
};
