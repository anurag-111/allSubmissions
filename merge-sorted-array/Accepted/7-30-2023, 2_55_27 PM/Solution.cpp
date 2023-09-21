// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m + n - 1;  // Pointer to the last element of the merged array
        int right = 0;        // Pointer to the first element of nums2
        
        // Merge nums1 and nums2 from the end of nums1
        while (left > m - 1 && right < n) {
            // Swap elements at left and right positions to put the smaller element in nums1
            swap(nums1[left], nums2[right]);
            left--;    // Move left pointer towards the beginning of the merged array
            right++;   // Move right pointer towards the end of nums2
        }
        
        sort(nums1.begin(), nums1.end());  // Sort the merged nums1 array
    }   
};

// Time Complexity: O((m + n) log (m + n)) due to the sorting step.
// Space Complexity: O(1) since no additional space is used other than the input vectors.
// In-place merge without using any extra space.
