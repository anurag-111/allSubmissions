// https://leetcode.com/problems/split-array-largest-sum

class Solution {
private: 
    bool isPossible(vector<int>& nums, int n, int mid) {
        int require_arr = 1;
        int sum = 0;

        // checks if the condition of splitting nums into k non-empty 
        // subarrays such that the largest sum of any subarray is minimized is satisfied.
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if(sum > mid){
                require_arr++;
                sum = nums[i];
            }
        }
        return require_arr <= n;
    }
    
public:
    int splitArray(vector<int>& nums, int k) {
        int max_arr = 0;
        int sum = 0;

        // calculating the maximum element and the sum of the array.
        for(int val : nums) {
            sum += val;
            max_arr = max(max_arr, val);
        }

        // if the number of distribution is eqaul to the size of array 
        // just return the maximum of the array
        if(nums.size() == k) { 
            return max_arr;
        }

        // low will be set to the maximum element.
        int low = max_arr; 

        // high will be set to the sum of the given array
        int high = sum;

        int answer = 0;

        // binary search applied on the values present in the array
        while(low <= high) {
            int mid = low + (high - low) / 2;   //overflow prevented.

            if(isPossible(nums, k, mid)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return answer;
    }
};