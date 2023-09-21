// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; // at the end of the first array
        int j = n - 1; // at the end of the second array
        int k = m + n - 1; // at the end of the resultant array
        
        while(j >= 0) {
            // run this loop till the elements of the second array get exhausted
            
            if(i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};