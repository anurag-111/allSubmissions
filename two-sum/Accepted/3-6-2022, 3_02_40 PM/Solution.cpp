// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec1, vec2;
        vec1 = nums;
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        while(i!=j)
        {
            int sum = nums[i] + nums[j];
            if(sum==target)
            break;
            else if(sum>target)
            j--;
            else
            i++;
        }
        for(int k=0;k<vec1.size();k++)
        {
            if(vec1[k]==nums[i])
                vec2.push_back(k);
            else if(vec1[k]==nums[j])
                vec2.push_back(k);
        }
        return vec2;
    }
};