// https://leetcode.com/problems/find-k-closest-elements

// Optimized approach for finding 'k' closest elements to 'x' in a sorted array 'arr'.

class Solution {
public:
    vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;
        
        // Perform binary search to find the starting index of the 'k' closest elements.
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // If the difference between x and the mid element is greater than the difference
            // between the (mid + k)th element and x, move the left pointer to mid + 1.
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                // Otherwise, move the right pointer to mid.
                right = mid;
            }
        }
        
        // Create the result vector containing the 'k' closest elements.
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(arr[left + i]);
        }
        
        return result;
    }
};

// Time complexity: O(log(N - k)) - Due to the binary search where 'N' is the size of the 
// input array 'arr' and 'k' is the number of closest elements to find.

// Space complexity: O(k) - Due to the result vector that contains the 'k' 
// closest elements. The space used by other variables is constant (O(1)).