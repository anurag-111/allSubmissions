// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> mymap; // Create a hash table
        vector<int> result; // For storing our indexes

        for(int i = 0; i < nums.size(); i++) {
            
            // Iterating over the array to find the remaining portion of the target
            if(mymap.find(target - nums[i]) != mymap.end()) {
                result.push_back(mymap[target - nums[i]]); // Inserting the index of the found element
                result.push_back(i); // Inserting the index of the elements beigs iterated
            } 

            mymap[nums[i]] = i; // Mapping of elements
        }
        
        return result;
    }
};