// https://leetcode.com/problems/3sum

// O(n ^ 3) Approach : TLE

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       set<vector<int>> foundTriplets;

        for(int i = 0; i < nums.size() - 2; i++) {
            for(int j = i + 1; j < nums.size() - 1; j++) {
                for(int k= j + 1; k < nums.size(); k++) {
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end());
                        foundTriplets.insert(triplet);
                    }
                }
            }
        }
        vector<vector<int>> threeSum(foundTriplets.begin(), foundTriplets.end());
        return threeSum;
    }
};

/*
Question : Purpose of the ordered set?

Answer   : An unordered set does not impose any specific order on the elements it stores. 
           Therefore, it cannot guarantee the unique and sorted order required for the 
           resulting triplets. While it may remove exact duplicates, it does not take 
           into account the order of elements within a triplet.
           
           In summary, a set or an ordered set is appropriate in this case because it 
           automatically removes duplicates and maintains a sorted order, which is necessary 
           for finding unique triplets with a sum of zero.
*/

