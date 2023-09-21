// https://leetcode.com/problems/koko-eating-bananas

class Solution {
private :
    int findMax(vector<int> &piles) {
        int maxPile = INT_MIN;
        for(int pile : piles) {
            if(pile > maxPile) {
                maxPile = pile;
            }
        }
        return maxPile;
    }

    int hoursTaken(vector<int> &piles, int hours) {
        int totalHours = 0;

        for(int i = 0; i < piles.size(); i++) {
            totalHours += ceil(double(piles[i]) / double(hours));
        }

        return totalHours;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int totalHours = hoursTaken(piles, mid);
            
            if(totalHours <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};