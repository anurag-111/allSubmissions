// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    /**
     * Search for the target value in a rotated sorted array.
     * 
     * @param nums The rotated sorted array.
     * @param target The value to search for.
     * @return The index of the target value if found, otherwise -1.
     */
    int search(vector<int>& nums, int target) {
        int left = 0;                       // Leftmost index of the search range
        int right = nums.size() - 1;        // Rightmost index of the search range

        while (left <= right) {
            int mid = left + (right - left) / 2;  // Calculate the middle index

            if (nums[mid] == target) {
                // Target found at index 'mid'
                return mid;
            }

            if (nums[left] <= nums[mid]) {
                // Left array is sorted

                if (nums[left] <= target && target <= nums[mid]) {
                    // Target is within the sorted range of the left array
                    right = mid - 1;  // Adjust the right pointer
                } else {
                    // Target is not within the sorted range of the left array
                    left = mid + 1;  // Adjust the left pointer
                }
            } else {
                // Right array is sorted

                if (nums[mid] <= target && target <= nums[right]) {
                    // Target is within the sorted range of the right array
                    left = mid + 1;  // Adjust the left pointer
                } else {
                    // Target is not within the sorted range of the right array
                    right = mid - 1;  // Adjust the right pointer
                }
            }
        }

        // Target not found
        return -1;
    }
};

/*
Time Complexity: O(log N)

The search is performed using binary search, which reduces 
the search space by half in each iteration. Hence, the time 
complexity is logarithmic, O(log N), where N is the number 
of elements in the input array.
    
Space Complexity: O(1)

The algorithm uses a constant amount of extra space for the 
variables left, right, and mid. Therefore, the space complexity 
is O(1), indicating constant space usage regardless of the input size.
*/



