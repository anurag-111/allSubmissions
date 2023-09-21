// https://leetcode.com/problems/calculate-delayed-arrival-time

class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        // Convert the arrival time to hours and minutes
        int arrival_hours = arrivalTime / 100;
        int arrival_minutes = arrivalTime % 100;

        // Convert the delayed time to hours and minutes
        int delayed_hours = delayedTime / 100;
        int delayed_minutes = delayedTime % 100;

        // Add the delayed time to the arrival time
        int updated_hours = arrival_hours + delayed_hours;
        int updated_minutes = arrival_minutes + delayed_minutes;

        // Adjust the hours and minutes if they exceed 24 and 60, respectively
        if (updated_minutes >= 60) {
            updated_hours++;
            updated_minutes -= 60;
        }

        if (updated_hours >= 24) {
            updated_hours -= 24;
        }

        // Convert the updated hours and minutes back to a 24-hour time format
        int updated_arrival_time = updated_hours * 100 + updated_minutes;

        return updated_arrival_time == 24 ? 0 : updated_arrival_time;
    }
};