// https://leetcode.com/problems/gas-station

class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int currentGas = 0; // Track the current gas remaining
        int totalGas = 0; // Track the total gas remaining after completing the tour
        int startStationIndex = 0; // Store the starting gas station index

        for (int i = 0; i < cost.length; i++) {
            currentGas += gas[i] - cost[i]; // Calculate net gas remaining at each station

            if (currentGas < 0) {
                totalGas += currentGas; // Update total gas remaining (negative value represents the gas deficit)
                currentGas = 0; // Reset currentGas as we start from the next station
                startStationIndex = i + 1; // Update the potential starting station index
            }
        }
        
        totalGas += currentGas; // Add the remaining currentGas to the totalGas
        return totalGas >= 0 ? startStationIndex : -1; // Check if totalGas is non-negative, return the starting position if true, otherwise -1
    }
}
