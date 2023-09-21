// https://leetcode.com/problems/xor-operation-in-an-array

// Approach 1 :
// TC : O(N)
// SC : O(N)
// class Solution {
// public:
//     int xorOperation(int n, int start) {
//         vector<int> nums(n);
//         for(int i = 0; i < n; i++) {
//             nums[i] = start + 2 * i;
//         }
        
//         int sum = 0;
//         for(int i = 0; i < n; i++) {
//             sum = sum ^ nums[i];
//         }
        
//         return sum;
//     }
// };

// Approach 2 :
// TC : O(N)
// SC : O(1)
class Solution {
public:
    int xorOperation(int n, int start) {
        int xorResult = 0;
        for(int i = 0; i < n; i++) {
            xorResult = xorResult ^ (start + 2 * i);
        }
        return xorResult;
    }
};