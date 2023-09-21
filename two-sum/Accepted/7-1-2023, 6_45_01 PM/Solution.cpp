// https://leetcode.com/problems/two-sum

#include <unordered_map>
#include <vector>

class Solution {
public:
    // Function to find two numbers in the given vector that add up to the target value
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap; // Map to store numbers and their indices
        vector<int> result; // Vector to store the result indices

        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // Calculate the complement value

            // Check if the complement value exists in the map
            if(numMap.find(complement) != numMap.end()) { 
                result.push_back(numMap[complement]); // Add the index of the complement value to the result vector
                result.push_back(i); // Add the current index to the result vector
                break; // Exit the loop since we have found the result
            }

            numMap[nums[i]] = i; // Store the current number and its index in the map
        }

        return result; // Return the result vector
    }
};
