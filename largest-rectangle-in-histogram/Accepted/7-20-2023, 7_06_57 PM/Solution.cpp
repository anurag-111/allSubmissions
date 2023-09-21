// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st; // Stack to keep track of indices of bars
        int maxArea = 0; // Variable to store the maximum area

        for (int i = 0; i <= n; i++) {
            // Push an extra -1 at the end of the heights array to ensure all elements in the stack are processed.
            // If the current index 'i' is equal to 'n', set the current height to 0, 
            // as it acts as the right boundary for any remaining bars in the stack.
            int currHeight = (i == n) ? 0 : heights[i];

            // While the stack is not empty and the height of the current bar (heights[i]) 
            // is less than or equal to the height of the bar at the top of the stack (heights[st.top()]), 
            // keep popping elements from the stack.
            while (!st.empty() && heights[st.top()] >= currHeight) {
                // Get the height of the bar at the top of the stack and remove it from the stack.
                int height = heights[st.top()];
                st.pop();

                // Calculate the width of the rectangle using the left and right boundaries.
                int width = st.empty() ? i : (i - st.top() - 1);

                // Calculate the area of the rectangle formed by the current bar.
                int area = height * width;

                // Update the maximum area if needed.
                maxArea = max(maxArea, area);
            }

            // Push the current index 'i' onto the stack to keep track of the bar's index for the next iterations.
            st.push(i);
        }

        // Return the maximum area found.
        return maxArea;
    }
};
