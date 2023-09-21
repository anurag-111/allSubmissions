// https://leetcode.com/problems/find-the-difference-of-two-arrays

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> list(2);
        unordered_set<int> distinctNums1(begin(nums1), end(nums1));
        unordered_set<int> distinctNums2(begin(nums2), end(nums2));

        for(int num : distinctNums1) {
            if(distinctNums2.count(num) == 0) {
                list[0].push_back(num);
            }
        }

        for(int num : distinctNums2) {
            if(distinctNums1.count(num) == 0) {
                list[1].push_back(num);
            }
        }

        return list;     
    }
};