// https://leetcode.com/problems/kth-missing-positive-number

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0; // Pointer to the leftmost element
        int right = arr.size() - 1; // Pointer to the rightmost element

        while (left <= right) {
            int mid = left + (right - left) / 2; // Calculate the middle index
            int missing = arr[mid] - (mid + 1); // Calculate the number of missing elements

            if (missing < k) {
                left = mid + 1; // Adjust the left pointer
            } else {
                right = mid - 1; // Adjust the right pointer
            }
        } 

        // Return the k-th missing positive number
        return right + k + 1;
    }
};
