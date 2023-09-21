// https://leetcode.com/problems/product-of-array-except-self

#include <vector>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();

        vector<int> result(size, 1);        // Stores the final result

        int leftProduct = 1;    // Product of elements to the left of the current element

        // Calculate products of elements before the current index
        for (int i = 0; i < size; i++) {
            result[i] *= leftProduct;
            leftProduct *= nums[i];
        }

        int rightProduct = 1;   // Product of elements to the right of the current element

        // Calculate products of elements after the current index and multiply with the existing result
        for (int i = size - 1; i >= 0; i--) {
            result[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return result;
    }
};
