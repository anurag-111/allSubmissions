// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    /**
     * Find the peak element in an array.
     *
     * @param nums The input array.
     * @return The index of the peak element.
     */
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        // Check if the first element is a peak
        if (n == 1 || nums[0] > nums[1]) {
            return 0;
        }

        // Check if the last element is a peak
        if (nums[n - 1] > nums[n - 2]) {
            return n - 1;
        }

        int low = 1;                           // Leftmost index of the search range
        int high = n - 2;                      // Rightmost index of the search range

        while (low <= high) {
            int mid = low + (high - low) / 2;  // Calculate the middle index

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                // Peak element found
                return mid;
            } else if (nums[mid] < nums[mid + 1]) {
                // Peak is in the right part of the array
                low = mid + 1;                 // Adjust the low pointer
            } else {
                // Peak is in the left part of the array
                high = mid - 1;                // Adjust the high pointer
            }
        }

        return -1;  // No peak element found
    }
};


/*
    Time Complexity: O(log N)

    The search is performed using binary search, which reduces the search space by half in each iteration. 
    Hence, the time complexity is logarithmic, O(log N), where N is the number of elements in the input array.
    
    Space Complexity: O(1)

    The algorithm uses a constant amount of extra space for the variables n, low, high, and mid. 
    Therefore, the space complexity is O(1), indicating constant space usage regardless of the input size.

*/