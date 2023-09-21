// https://leetcode.com/problems/sliding-subarray-beauty

/**
 * The Solution class implements a method to find the xth smallest negative integer in sliding windows
 * of size k in an array of integers.
 */
class Solution {
public:
    /**
     * getSubarrayBeauty method finds the xth smallest negative integer in sliding windows of size k
     * in the given array of integers.
     *
     * @param nums A vector of integers representing the input array.
     * @param k An integer representing the size of sliding windows.
     * @param x An integer representing the position of the smallest negative integer to be found.
     * @return A vector of integers representing the xth smallest negative integer in each sliding window.
     */
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size(); 
        vector<int> freq(51, 0), ans; // Create a vector to store frequency of negative numbers and result

        // Iterate through the input array with a sliding window approach
        for(int i = 0, j = 0; i < n; i++) {
            
            // Count frequency of negative numbers in current sliding window
            if(nums[i] < 0) {
                freq[abs(nums[i])]++;
            }
        
            if(i - j + 1 >= k) { // If window size is equal to k
                
                // Counter for xth smallest number
                int cnt = 0; 

                // Calculate xth smallest number in current sliding window
                for(int L = 50; L >= 1; L--) {
                    cnt += freq[L]; // Add frequency of negative number to cnt
                    if(cnt >= x) { 
                        ans.push_back(-L); // Push the xth smallest negative number into result vector
                        break;
                    }
                }

                // If no xth smallest number is present in current window, push 0 into result vector
                if(cnt < x) {
                    ans.push_back(0);
                }

                // Remove the leftmost element from the window and update frequency vector
                if(nums[j] < 0) {   
                    freq[abs(nums[j])]--; // Decrease frequency of leftmost elementfreq[abs(nums[j])]--;
                }

                j++; // Slide the window to the right
            }
        }

        return ans; // Return the result vector
    }
};


/*  
    Coplexity :
        Time Complexity : O(N * 50)
        Space Complexity : O(50)
*/

