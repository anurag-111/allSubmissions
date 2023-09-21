// https://leetcode.com/problems/make-array-empty

class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        // Map to store the indices of each number in the array
        map<int, set<int>> indexMap;

        // Initialize the map
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            indexMap[nums[i]].insert(i);
        }

        // Variable to store the number of operations needed to empty the array
        long long operations = 0;

        // Keep looping until the array is empty
        while (n > 0) {
            // Start a new subarray with the smallest value in the map
            int subarrayLength = 1;
            int currentValue = indexMap.begin()->first;
            int currentIndex = *indexMap.begin()->second.begin();

            // Remove the current index from the map
            indexMap[currentValue].erase(currentIndex);
            if (indexMap[currentValue].empty()) {
                indexMap.erase(currentValue);
            }

            // Keep adding elements to the subarray as long as they form a non-decreasing sequence
            while (!indexMap.empty()) {
                subarrayLength++;

                // If the current value is in the map and there is an index greater than the current index,
                // add that index to the subarray
                if (indexMap.find(currentValue) != indexMap.end() && *indexMap[currentValue].rbegin() > currentIndex) {
                    currentIndex = *indexMap[currentValue].upper_bound(currentIndex);
                    indexMap[currentValue].erase(currentIndex);
                    if (indexMap[currentValue].empty()) {
                        indexMap.erase(currentValue);
                    }
                }
                // If there is a smaller value in the map, add the index of the largest element in that set to the subarray
                else if (indexMap.begin()->first > currentValue && *indexMap.begin()->second.rbegin() > currentIndex) {
                    currentValue = indexMap.begin()->first;
                    currentIndex = *indexMap[currentValue].upper_bound(currentIndex);
                    indexMap[currentValue].erase(currentIndex);
                    if (indexMap[currentValue].empty()) {
                        indexMap.erase(currentValue);
                    }
                }
                // If neither condition is met, the current subarray is complete
                else {
                    subarrayLength--;
                    break;
                }
            }

            // Add the number of operations needed to empty the current subarray to the total operations count
            operations += n;
            n -= subarrayLength;
        }
        return operations;
    }
};
