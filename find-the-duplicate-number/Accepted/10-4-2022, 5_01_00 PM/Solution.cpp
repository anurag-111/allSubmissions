// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        
        for(int i=0; i<nums.size(); i++) {
            if(s.find(nums[i]) != s.end()) {
                return nums[i];
            }
            else{
                s.insert(nums[i]);
            }
        }
        return -1;
    }
};