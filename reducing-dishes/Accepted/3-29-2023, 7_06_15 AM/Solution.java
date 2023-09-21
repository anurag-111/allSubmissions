// https://leetcode.com/problems/reducing-dishes

class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);
        int postSum = 0, cur = 0,res = 0;

        for(int i = satisfaction.length - 1; i >= 0; i--){
            postSum += satisfaction[i]; //postsum is the sum of values from arr[i] to the end
            cur += postSum; //cur is the satisfaction score we have seen so far
            res = Math.max(res, cur);
        }
        return res;
    }
}