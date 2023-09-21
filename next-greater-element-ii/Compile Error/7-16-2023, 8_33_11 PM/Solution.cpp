// https://leetcode.com/problems/next-greater-element-ii

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    
    /**
     * @brief Finds the next greater elements in a circular manner.
     * 
     * Given an array, this function finds the next greater element for each element in the array,
     * considering the array as circular (i.e., the last element is followed by the first element).
     * 
     * @param arr The input array.
     * @return A vector containing the next greater elements for each element in the input array.
     */
    vector<int> nextGreaterCircular(vector<int>& arr) {
        vector<int> nextGreater(arr.size(), -1);
        stack<int> st; // Stack to store indices of elements
        
        // Run the outer loop two times to consider the array as circular
        for (int j = 0; j < 2; j++) {
            // Traverse the array to find the next greater element for each element
            for (int i = 0; i < arr.size(); i++) {
                // While the stack is not empty and the current element is greater than the element at the top of the stack
                while (!st.empty() && arr[st.top()] < arr[i]) {
                    // Update the next greater element for the element at the top of the stack
                    int stackTop = st.top();
                    nextGreater[stackTop] = arr[i];
                    st.pop();
                }
                // Push the index of the current element onto the stack
                st.push(i);
            }
        }
        
        return nextGreater;
    }
};

// Time Complexity: 
// O(N), where N is the number of elements in the input array.
// The algorithm processes each element in the array exactly twice.

// Space Complexity: 
// O(N), where N is the number of elements in the input array.
// The space is used to store the output array and the stack, both of 
// which can have at most N elements.
