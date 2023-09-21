// https://leetcode.com/problems/car-fleet

class Solution {
public:
    /**
     * Calculate the number of car fleets that reach the target.
     * 
     * @param target The target position.
     * @param position The positions of cars.
     * @param speed The speeds of cars.
     * @return The number of car fleets.
     */
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if (position.empty() || speed.empty()) {
            // Empty input arrays, no car fleet possible
            return 0;
        }
        
        map<int, double, greater<int>> carMap; // Map to store position and time-to-target ratios
        
        for (int i = 0; i < position.size(); i++) {
            double timeToTarget = double(target - position[i]) / speed[i];
            carMap[position[i]] = timeToTarget; // Store position and time-to-target ratio in the map
        }
        
        int carFleetCount = 0;  // Number of car fleets
        double currentFleetTime = 0.0;  // Current maximum time-to-target ratio
        
        for (auto car : carMap) {
            if (car.second > currentFleetTime) {
                currentFleetTime = car.second;
                carFleetCount++;  // Increase car fleet count if the time-to-target ratio is greater than the current maximum
            }
        }
        
        return carFleetCount;
    }
};

/*
    Time Complexity: O(N log N)
    ---------------------------

    The time complexity is dominated by the sorting of the map carMap, which has N elements. 
    The insertion of elements into the map takes O(log N) time for each element. 
    Hence, the overall time complexity is O(N log N), where N is the number of cars.
    
    Space Complexity: O(N)
    ----------------------

    The space complexity is determined by the map carMap, which can store up to N elements. 
    Therefore, the space complexity is O(N), where N is the number of cars.
*/