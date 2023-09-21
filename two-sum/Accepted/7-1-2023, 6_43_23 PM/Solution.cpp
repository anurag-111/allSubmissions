// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> result;

        for(int i = 0; i < nums.size(); i++) {
            if(map.find(target - nums[i]) != map.end()) { 
                result.push_back(map[target - nums[i]]);
                result.push_back(i);
            }

            map[nums[i]] = i;
        }
        return result;
    }
};