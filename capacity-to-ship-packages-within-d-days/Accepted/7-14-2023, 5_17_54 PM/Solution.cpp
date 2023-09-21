// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

class Solution {
    private :
            bool isPossible(vector<int> &weights, int leastCapacity, int days) {
                long long currentCapacity = 0;
                int reqDays = 1;

                for(int i = 0; i < weights.size(); i++) {
                    currentCapacity += weights[i];
                    
                    if(currentCapacity > leastCapacity) {
                        reqDays++;
                        currentCapacity = weights[i];
                    }
                }

                return reqDays <= days;
            }

    public :
        int shipWithinDays(vector<int>& weights, int days) {
            int maxWeight = INT_MIN;
            long long sumOfWeights = 0;

            for(int i = 0; i < weights.size(); i++) {
                maxWeight = max(maxWeight, weights[i]);
                sumOfWeights += weights[i];
            } 

            int low = maxWeight;
            long long high = sumOfWeights;

            while(low <= high) {
                int mid = low + (high - low) / 2;

                if(isPossible(weights, mid, days)) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            return low;
        }
};