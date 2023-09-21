// https://leetcode.com/problems/minimum-time-to-complete-trips

class Solution {
public:
    long long minimumTime(vector<int> &time, long long totalTrips) {
        long long low = 1;
        long long high = time[0] * totalTrips;
        long long min_time;

        // O(log n), where n = time[0] * totalTrips.
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(isValid(time, totalTrips, mid)) {
                min_time = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return min_time;
    }

    bool isValid(vector<int> &time, int totalTrips, int curr_time) {
        long long n = time.size();
        vector<int> trips(n);
        long long num_trips = 0;

        // O(n), where n = size of time array.
        for(long long i = 0; i < n; i++) {
            trips[i] = curr_time / time[i];
            num_trips += trips[i];
        }

        if(num_trips >= totalTrips) {
            return true;
        } else {
            return false;
        }

    }
};




