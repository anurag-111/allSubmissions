// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

class Solution {
private: 
    bool isPossible(vector<int>& weights, int days, int mid) {
        int require_days = 1;
        int sum = 0;

        // checks if the the value of mid (the capacity) satisfies the condition 
        // of being the minimum to ship all the packages.
        for(int i = 0; i <weights.size(); i++) {
            sum += weights[i];

            if(sum > mid){
                require_days++;
                sum = weights[i];
            }
        }
        return require_days <= days;
    }
    
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int max_weight = 0;
        int sum = 0;

        // calculating the maximum weight and the sum of the weights.
        for(int val : weights) {
            sum += val;
            max_weight = max(max_weight, val);
        }

        // if the number of days are equal to the the size of the weights then we 
        // just return the maximum weight on a given individual day.
        if(weights.size() == days) { 
            return max_weight;
        }

        // low will be set to the highest given weights.
        int low = max_weight; 

        // high will be set to the sum of the given weights
        int high = sum;

        int answer = 0;

        // binary search applied on the weights that container has to ship.
        while(low <= high) {
            int mid = low + (high - low) / 2;   //overflow prevented.

            if(isPossible(weights, days, mid)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return answer;
    }
};