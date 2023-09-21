// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    /**
     * Find the minimum element in a rotated sorted array.
     *
     * @param nums The rotated sorted array.
     * @return The minimum element.
     */
    int findMin(vector<int>& nums) {
        int low = 0;                              // Leftmost index of the search range
        int high = nums.size() - 1;               // Rightmost index of the search range

        while (low < high) {
            int mid = low + (high - low) / 2;      // Calculate the middle index

            if (nums[mid] > nums[high]) {
                // Minimum element is in the right part of the array
                low = mid + 1;                     // Adjust the low pointer
            } else {
                // Minimum element is in the left part of the array or at the middle element
                high = mid;                        // Adjust the high pointer
            }
        }

        return nums[low];                          // Return the element at the low index as the minimum
    }
};


/*

Time Complexity: O(log N)

The search is performed using binary search, which reduces the search space by half in each iteration. Hence, the time complexity is logarithmic, O(log N), where N is the number of elements in the input array.

Space Complexity: O(1)

The algorithm uses a constant amount of extra space for the variables low, high, and mid. Therefore, the space complexity is O(1), indicating constant space usage regardless of the input size.

--------------------------------------------------------------------------------------------------------

Since we always round down for mid, right would never be the same as mid. 
This situation becomes very clear in the case of a two element array 
(or just in general when the left and right pointers are adjacent. I.e., 
for an input [5,1]. We have l=0,m=0,r=1, due to our rounding down (floor division). 
If we didn't use floor division, with this input, we could end up with l=0,m=1,r=1, 
so m and r are pointing at the same one. This causes several problems. 
It breaks our loop invariant that m and r are never the same. And because 
it breaks this invariant, it causes us to enter an infinite loop. Since we don't 
handle equals with our code, so we're just stuck here eternally.


*/