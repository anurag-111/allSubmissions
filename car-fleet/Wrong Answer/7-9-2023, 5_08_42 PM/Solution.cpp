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
        
        int currentFleet = 0;  // Current maximum time-to-target ratio
        int carFleet = 0;     // Number of car fleets
        
        for (auto car : carMap) {
            if (car.second > currentFleet) {
                currentFleet = car.second;
                carFleet++;  // Increase car fleet count if the time-to-target ratio is greater than the current maximum
            }
        }
        
        return carFleet;
    }
};
