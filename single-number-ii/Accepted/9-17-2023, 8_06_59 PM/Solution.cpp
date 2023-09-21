// https://leetcode.com/problems/single-number-ii

// Approach 1 : Using hashmap
// TC : O(N)
// SC : O(N)
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map <int, int> freqMap;
//         for(int i = 0; i < nums.size(); i++) {
//             freqMap[nums[i]]++;
//         }

//         int result;
//         for(auto num : freqMap) {
//             if(num.second == 1) {
//                 result = num.first;
//             }
//         }
//         return result;
//     }
// };

// Approach 2 : Using bit manipulation
// TC : O(32 * N)
// SC : O(1)
// class Solution {
//   public:
//       int singleNumber(vector<int>& nums) {
//         int result = 0;
//         // Each number is represented by 32 bits, hence the traversal
//         for(int i = 0; i < 32; i++) {
//           int sum = 0;
//           for(int j = 0; j < nums.size(); j++) {
//             if(((nums[j] >> i) & 1) == 1) {
//               sum++;
//             }
//           } 
//           sum = sum % 3;
//           if(sum != 0) {
//             result = result | (sum << i);
//           }          
//         } 
//         return result;               
//       }
// };

// Approach 3 : Using optimized Bit Manipulation
// TC : O(N)
// SC : O(1)
  class Solution {
  public:
      int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        for(int i = 0; i < nums.size(); i++) {
          ones = (ones ^ nums[i]) & ~(twos);
          twos = (twos ^ nums[i]) & ~(ones);
        }                
        return ones;
      }
};

