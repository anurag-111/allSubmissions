// https://leetcode.com/problems/gas-station

class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int sum = 0;
        int total = 0;
        int position = 0;

        for(int i = 0; i < cost.length; i++) {
            sum += gas[i] - cost[i];

            if(sum < 0) {
                total += sum;
                sum = 0;
                position = ++i;
            }
        }
        
        total += sum;
        return total >= 0 ? position : -1;
        
    }
}