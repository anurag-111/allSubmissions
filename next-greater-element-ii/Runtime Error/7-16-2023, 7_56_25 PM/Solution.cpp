// https://leetcode.com/problems/next-greater-element-ii

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> numStack; // Stack to store elements for finding the next greater element
        const int MAX_NUM = 10001; // Maximum possible value of an element in nums
        vector<int> nextGreater(MAX_NUM, -1); // Array to store the next greater element for each number
        vector<int> result(nums.size(), -1); // Array to store the final result
        
        // Two passes on nums to handle circular array behavior
        for (int pass = 0; pass < 2; pass++) {
            for (int i = 0; i < nums.size(); i++) {
                while (!numStack.empty() && numStack.top() < nums[i]) {
                    nextGreater[numStack.top()] = nums[i];
                    numStack.pop();
                }
                numStack.push(nums[i]);
            }
        }
        
        // Find the next greater element for each number in nums
        for (int i = 0; i < nums.size(); i++) {
            if (nextGreater[nums[i]]) {
                result[i] = nextGreater[nums[i]];
            }
        }
        
        return result;
    }
};
