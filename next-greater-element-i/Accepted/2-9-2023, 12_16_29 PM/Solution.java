// https://leetcode.com/problems/next-greater-element-i

class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        
        Map<Integer, Integer> hashMap = new HashMap<>();
        Stack<Integer> stk = new Stack<>();
        
        for (int num : nums2) {
            
            while (!stk.isEmpty() && stk.peek() <= num) {
                hashMap.put(stk.peek(), num);
                stk.pop();
            }
            
            stk.push(num);
        }
        
        for (int i = 0; i < nums1.length; i++) {
            nums1[i] = hashMap.getOrDefault(nums1[i], -1);
        }
        
        return nums1;
        
    }
}