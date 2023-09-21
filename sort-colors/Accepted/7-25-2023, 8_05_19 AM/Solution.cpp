// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;       // Pointer to the region of 0s (elements less than pivot)
        int mid = 0;        // Pointer to the region of 1s (elements equal to pivot)
        int right = nums.size() - 1;  // Pointer to the region of 2s (elements greater than pivot)

        // Loop until mid pointer crosses the right pointer
        while (mid <= right) {
            switch (nums[mid]) {
                case 0:  // If current element is 0
                    swap(nums[left], nums[mid]);    // Swap it with the element at left pointer
                    left++;                         // Move left pointer to the right
                    mid++;                          // Move mid pointer to the right
                    break;
                case 1:  // If current element is 1
                    mid++;                          // Move mid pointer to the right
                    break;
                case 2:  // If current element is 2
                    swap(nums[mid], nums[right]);   // Swap it with the element at right pointer
                    right--;                        // Move right pointer to the left
                    break;
            }
        }
    }
};

// Dutch Flag Algo

// [0 ... low - 1] -> 0
// [high + 1 ... n] -> 2

// 1. If the element is less than pivot, swap it with the element at index low, 
// and then increment both low and mid.
    
// 2. If the element is equal to pivot, increment mid only.
    
// 3. If the element is greater than pivot, swap it with the element at index high, and then decrement high.