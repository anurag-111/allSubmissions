// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDiff = INT_MAX;
        int closestSum = 0;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right) {
                int currSum = nums[i] + nums[left] + nums[right];

                int currDiff = abs(target - currSum);

                if(currDiff == 0) {
                    return target;
                }

                if(currDiff < minDiff) {
                    minDiff = currDiff;
                    closestSum = currSum;
                }

                if(currSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return closestSum;
    }
};