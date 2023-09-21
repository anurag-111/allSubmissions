// https://leetcode.com/problems/contains-duplicate

#include <unordered_set>
#include <vector>

class Solution {
public:
    // Function to check if there are any duplicate elements in the given vector
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uniqueNums; // Set to store unique numbers encountered

        for(int num : nums) {
            // Check if the current number already exists in the set
            if(uniqueNums.find(num) != uniqueNums.end()) {
                // Duplicate number found, return true
                return true;
            } else {
                // Add the current number to the set
                uniqueNums.insert(num);
            }
        }

        // No duplicates found
        return false;
    }
};
