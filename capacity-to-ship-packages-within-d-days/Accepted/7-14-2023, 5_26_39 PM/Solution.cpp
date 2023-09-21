// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

class Solution {
private:
    // Function to check if it is possible to ship all weights within the given capacity and days
    bool isPossible(vector<int>& weights, int capacity, int days) {
        long long currentCapacity = 0; // Current capacity of the ship
        int reqDays = 1; // Required number of days to ship all weights

        for (int i = 0; i < weights.size(); i++) {
            currentCapacity += weights[i]; // Add weight to the current capacity

            // If the current capacity exceeds the given capacity, update the ship and increment required days
            if (currentCapacity > capacity) {
                reqDays++;
                currentCapacity = weights[i];
            }
        }

        return reqDays <= days; // Check if required days are within the given limit
    }

public:
    // Function to find the minimum capacity needed to ship all weights within the given number of days
    int shipWithinDays(vector<int>& weights, int days) {
        // Find the maximum weight and sum of weights
        int maxWeight = 0;
        long long sumOfWeights = 0;
        for (int i = 0; i < weights.size(); i++) {
            maxWeight = max(maxWeight, weights[i]);
            sumOfWeights += weights[i];
        }

        int minCapacity = maxWeight; // Minimum capacity needed to ship all weights
        long long maxCapacity = sumOfWeights; // Maximum capacity needed to ship all weights

        // Binary search to find the minimum capacity
        while (minCapacity <= maxCapacity) {
            int midCapacity = minCapacity + (maxCapacity - minCapacity) / 2;

            if (isPossible(weights, midCapacity, days)) {
                maxCapacity = midCapacity - 1;
            } else {
                minCapacity = midCapacity + 1;
            }
        }

        return minCapacity;
    }
};


/*
    Time Complexity: O(N * log(S))

    Calculating the maximum weight and sum of weights: O(N), where N is the number of elements in the "weights" vector.
    Binary search to find the minimum capacity: O(log(S)), where S is the sum of weights.
    The isPossible function is called multiple times during the binary search: O(N).
    Overall, the time complexity is O(N + log(S) * N), which can be simplified to O(N * log(S)).
    
    
    Space Complexity: O(1)


*/
