// https://leetcode.com/problems/maximum-sum-with-exactly-k-elements

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>()); 
        int score = 0;
        for (int i = 0; i < k; i++) {
            int m = nums[i]; 
            score += m; 
            nums.push_back(m + 1); 
        }
        return score;
    }
};