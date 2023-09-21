// https://leetcode.com/problems/shuffle-the-array

// Appraoch 1 : Using an output array
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> numbers;
        for(int i = 0; i < n; i++) {
            numbers.push_back(nums[i]);
            numbers.push_back(nums[i + n]);
        }
        return numbers;
    }
};