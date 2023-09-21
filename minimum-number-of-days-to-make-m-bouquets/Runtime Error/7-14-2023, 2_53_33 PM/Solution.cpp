// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets

class Solution {
public:
    /**
     * Checks if it is possible to create the desired number of bouquets within a given day.
     *
     * @param bloomDay The array representing the bloom day of each flower.
     * @param day The current day to check.
     * @param requiredBouquets The required number of bouquets.
     * @param flowersPerBouquet The number of flowers per bouquet.
     * @return True if it is possible to create the desired number of bouquets, False otherwise.
     */
    static bool isPossible(vector<int>& bloomDay, int day, int requiredBouquets, int flowersPerBouquet) {
        int count = 0;
        int bouquetCount = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                count++;
            } else {
                bouquetCount += (count / flowersPerBouquet);
                count = 0;
            }
        }

        bouquetCount += (count / flowersPerBouquet);
        return bouquetCount >= requiredBouquets;
    }

    /**
     * Finds the minimum number of days required to create the desired number of bouquets.
     *
     * @param bloomDay The array representing the bloom day of each flower.
     * @param requiredBouquets The required number of bouquets.
     * @param flowersPerBouquet The number of flowers per bouquet.
     * @return The minimum number of days required, -1 if it is impossible to create the desired number of bouquets.
     */
    static int minDays(vector<int>& bloomDay, int requiredBouquets, int flowersPerBouquet) {
        long long totalFlowers = (long long)(requiredBouquets * flowersPerBouquet);

        // Impossible case: there are fewer flowers than needed for the desired number of bouquets
        if (bloomDay.size() < totalFlowers) {
            return -1;
        }

        int minDay = INT_MAX;
        int maxDay = INT_MIN;

        // Find the minimum and maximum bloom days
        for (int i = 0; i < bloomDay.size(); i++) {
            if (minDay > bloomDay[i]) {
                minDay = bloomDay[i];
            }
            if (maxDay < bloomDay[i]) {
                maxDay = bloomDay[i];
            }
        }

        int low = minDay;
        int high = maxDay;

        // Binary search to find the minimum possible day
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(bloomDay, mid, requiredBouquets, flowersPerBouquet)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};

