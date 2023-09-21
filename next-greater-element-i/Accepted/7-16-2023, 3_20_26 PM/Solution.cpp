// https://leetcode.com/problems/next-greater-element-i


class Solution {
public:
    /**
     * @brief Finds the next greater element for each element in nums1 from the corresponding positions in nums2.
     * 
     * @param nums1 The first input vector.
     * @param nums2 The second input vector.
     * @return A vector containing the next greater elements for each element in nums1.
     */
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> numStack; // Stack to keep track of elements in nums2
        unordered_map<int, int> nextGreaterMap; // Store the next greater element for each element in nums2
        vector<int> result(nums1.size(), -1); // Result vector to store the next greater elements for nums1 elements
        
        for (int num : nums2) {
            // While the stack is not empty and the current num in nums2 is greater than the top element in the stack
            while (!numStack.empty() && num > numStack.top()) {
                // Update the next greater element for the top element in the stack
                nextGreaterMap[numStack.top()] = num;
                numStack.pop(); // Remove the processed element from the stack
            }
            numStack.push(num); // Push the current num in nums2 into the stack
        }
        
        for (int i = 0; i < result.size(); i++) {
            if (nextGreaterMap.find(nums1[i]) != nextGreaterMap.end()) {
                result[i] = nextGreaterMap[nums1[i]];
            } else {
                result[i] = -1;
            }
        }
        
        return result;
    }
};

