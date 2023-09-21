// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
    public int largestRectangleArea(int[] heights) {
        
        int n = heights.length;

        Stack<Integer> stk = new Stack<Integer>();

        int idx = 0, maxArea = 0;

        while (idx < n) {
            if (stk.isEmpty() || heights[stk.peek()] <= heights[idx]) {
                stk.push(idx++);
            } else {
                int height = heights[stk.pop()];
                int area = height * (stk.isEmpty() ? idx : (idx - stk.peek() -1));
                maxArea = Math.max(area, maxArea);
            }
        }

        while (!stk.isEmpty()) {
            int height = heights[stk.pop()];
            int area = height * (stk.isEmpty() ? idx : (idx - stk.peek() - 1));
            maxArea = Math.max(area, maxArea);
        }

        return maxArea;
    }
}