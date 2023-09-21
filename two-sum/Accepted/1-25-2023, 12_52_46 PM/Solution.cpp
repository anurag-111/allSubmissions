// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ans;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = (i + 1); j < nums.size(); j++) {
                
                if (nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        
        return ans;
    }
};

// [2,7,11,15] target = 9 output = [0, 1]
// [3,2,4] target = 6 output: [1, 2]


// // for (int i = 0; i < nums.size(); i++) {
//     for (int j = i + 1; j < nums.size(); j++) {
//         if (nums[i] + nums[j] ==  target) {
//             ans.push_back(i);
//             ans.push_back(j);
//             return ans;
//         }
//     }
// }
//O(n^2)