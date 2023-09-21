// https://leetcode.com/problems/summary-ranges

// [0,1,2,4,5,7]
// ["0->2", "4->5", "7"]

// Breakpoint occurs at 4, inserting 0 -> 2
// Update the pointers at 4

// Algo : Find the breakpoint, insert the already found sequence and then update 
// the pointers and repeat the process.

// Testcase : [0, 2, 4]
// Output : ["0", "2", "4"]

class Solution {
private:
    string formatRange(int start, int end) {
        if (start == end) {
            return to_string(start); // Return a single number as a string if the range has only one element
        } else {
            return to_string(start) + "->" + to_string(end); // Return the formatted range string
        }
    }

public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        if (n == 0) {
            return result; // If the input vector is empty, return an empty result vector
        }
        
        int start = nums[0]; // Initialize the start of the current range
        int end = nums[0]; // Initialize the end of the current range
        
        for (int i = 1; i < n; i++) {
            if (nums[i] == end + 1) {
                end = nums[i]; // Extend the current range
            } else {
                result.push_back(formatRange(start, end)); // Add the formatted range to the result vector
                start = end = nums[i]; // Start a new range with the current number
            }
        }
        
        result.push_back(formatRange(start, end)); // Add the last range to the result vector
        
        return result; // Return the result vector
    }
};
