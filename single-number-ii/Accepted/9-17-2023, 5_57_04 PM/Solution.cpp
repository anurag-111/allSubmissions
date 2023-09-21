// https://leetcode.com/problems/single-number-ii

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map <int, int> freqMap;
        for(int i = 0; i < nums.size(); i++) {
            freqMap[nums[i]]++;
        }

        int result;
        for(auto num : freqMap) {
            if(num.second == 1) {
                result = num.first;
            }
        }
        return result;
    }
};