// https://leetcode.com/problems/summary-ranges

import java.util.ArrayList;
import java.util.List;

class Solution {
    // Helper method to format the range as a string
    private String formatString(int start, int end) {
        if (start == end) {
            return Integer.toString(start); // Return a single number as a string if the range has only one element
        } else {
            return start + "->" + end; // Return the formatted range string
        }
    }
    
    // Main method to find and summarize ranges
    public List<String> summaryRanges(int[] nums) {
        List<String> result = new ArrayList<>();
        
        if (nums.length == 0) {
            return result; // If the input array is empty, return an empty result list
        }
        
        int rangeStart = nums[0]; // Initialize the start of the current range
        int rangeEnd = nums[0]; // Initialize the end of the current range
        
        for (int i = 1; i < nums.length; i++) {
            if (rangeEnd + 1 == nums[i]) {
                rangeEnd = nums[i]; // Extend the current range if the next number is consecutive
            } else {
                result.add(formatString(rangeStart, rangeEnd)); // Add the formatted range to the result list
                rangeStart = rangeEnd = nums[i]; // Start a new range with the current number
            }
        }
        
        result.add(formatString(rangeStart, rangeEnd)); // Add the last range to the result list
        
        return result; // Return the result list containing the summarized ranges
    }
}
