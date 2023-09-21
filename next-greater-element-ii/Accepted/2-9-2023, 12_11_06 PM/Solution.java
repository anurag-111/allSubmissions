// https://leetcode.com/problems/next-greater-element-ii



class Solution {
    public int[] nextGreaterElements(int[] nums) {
        
        int len = nums.length;
        Stack<Integer> stk = new Stack<>();
        int[] result = new int[len];
        Arrays.fill(result, -1);
        
        for (int idx = 0; idx < (len * 2); idx++) {
            
            while (!stk.isEmpty() && nums[stk.peek()] < nums[idx % len]) {
                result[stk.peek()] = nums[idx % len];
                stk.pop();
            }
            
            if (idx < len) {
                stk.push(idx);
            }
        }
        
        return result;
    }
}