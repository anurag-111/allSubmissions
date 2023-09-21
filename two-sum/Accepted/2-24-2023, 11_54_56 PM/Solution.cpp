// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> mymap;
        for(int i = 0; i < nums.size(); i++) {
            if(mymap.find(target - nums[i]) != mymap.end()) {
                result.push_back(mymap[target - nums[i]]);
                result.push_back(i);
            }
            mymap[nums[i]] = i;
        }
        return result;
    }
};