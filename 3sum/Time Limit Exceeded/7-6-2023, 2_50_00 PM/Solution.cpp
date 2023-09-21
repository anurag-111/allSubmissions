// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;

        for(int i = 0; i < nums.size(); i++) {
            set<int> hashSet;
            for(int j = i + 1; j < nums.size(); j++) {
                int target = -(nums[i] + nums[j]);
                if(hashSet.find(target) != hashSet.end()) {
                    vector<int> temp = {nums[i], nums[j], target};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashSet.insert(nums[j]);
            }
        }
        vector<vector<int>> threeSum (st.begin(), st.end());
        return threeSum;
    }
};