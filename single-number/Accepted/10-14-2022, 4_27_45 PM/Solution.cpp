// https://leetcode.com/problems/single-number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        //[1,1,2,2,4,4,5] , n=7
        for(int i = 0; i<nums.size()-1; i+=2){
            if(nums[i] != nums[i+1]){
                return nums[i];
            }
        }
        return nums[nums.size() - 1];
    }
};