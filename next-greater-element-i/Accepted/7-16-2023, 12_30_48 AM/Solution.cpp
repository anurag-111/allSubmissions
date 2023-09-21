// https://leetcode.com/problems/next-greater-element-i

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size(), -1);
        vector<int> nextGreater(10001, -1); // Stores the next greater element for each number in nums2
        stack<int> numStack; // Stack to store numbers from nums2

        // Finding the next greater element for each number in nums2
        for (auto num : nums2) {
            while (!numStack.empty() && numStack.top() < num) {
                nextGreater[numStack.top()] = num; // Set the next greater element for the number at the top of the stack
                numStack.pop(); // Pop the number from the stack
            }
            numStack.push(num); // Push the current number into the stack
        }

        // Finding the next greater element for each number in nums1
        for (int i = 0; i < nums1.size(); i++) {
            result[i] = nextGreater[nums1[i]]; // Assign the next greater element from the nextGreater array
        }

        return result;
    }
};