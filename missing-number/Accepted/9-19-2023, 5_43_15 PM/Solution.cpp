// https://leetcode.com/problems/missing-number

// Approach 1 : Binary Search
// Time Complexity : O(N log N)
// Space Complexity : O(1)
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int left = 0;
//         int right = nums.size() - 1;
//         sort(nums.begin(), nums.end());
//         while(left <= right) {
//             int mid = (left + right) / 2;
//             if(nums[mid] > mid) {
//                 right = mid - 1;
//             } else {
//                 left = mid + 1;
//             }
//         } 
//         return left;          
//     }
// };

// Approach 2 : Bit Manipulation
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int result = size;
        for(int i = 0; i < size; i++) {
            result = result ^ (i ^ nums[i]);
        }
        return result;
    }
};


// [3, 0, 1]       
// size = 3
// result = 011
// i = 0
// result = 011 ^ (000 ^ 011) = 011 ^ 011 = 000
// i = 1
// result = 000 ^ (001 ^ 000) = 000 ^ 001 = 001
// i = 2
// result = 001 ^ (010 ^ 001) = 001 ^ 011 = 010 -> 2
// missing number  = 2