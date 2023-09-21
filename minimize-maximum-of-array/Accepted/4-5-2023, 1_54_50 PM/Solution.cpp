// https://leetcode.com/problems/minimize-maximum-of-array

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long sum = 0, avg = 0, result = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            avg = (sum + i) / (i + 1);
            result = max(result, avg);
        }
        return result;
    }
    
};