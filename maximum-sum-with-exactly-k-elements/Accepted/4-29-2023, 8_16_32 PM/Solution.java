// https://leetcode.com/problems/maximum-sum-with-exactly-k-elements

class Solution {
    public int maximizeSum(int[] nums, int k) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        for (int num : nums) {
            maxHeap.add(num);
        }
        int score = 0;
        while (k-- > 0) {
            int top = maxHeap.poll();
            score += top;
            maxHeap.add(top + 1);
        }
        return score;
    }
}