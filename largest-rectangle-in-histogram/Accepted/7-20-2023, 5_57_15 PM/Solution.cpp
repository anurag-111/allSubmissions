// https://leetcode.com/problems/largest-rectangle-in-histogram

// Brute Force Approach :

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int leftBoundary[n];
        int rightBoundary[n];
        stack<int> st;

        for(int i = 0; i < n; i++) {
            
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                // We compare the height of the current bar (heights[i]) with the height 
                // of the bar at the top of the stack (heights[st.top()]). We want to find 
                // the leftmost boundary of the current bar, and for that, we need to find the 
                // index of the first bar with a smaller height on its left side. Therefore, 
                // we pop elements from the stack until the stack becomes empty or the height 
                // of the bar at the top of the stack is strictly less than the height of the current bar.
                st.pop();
            }

            
            if(st.empty()) {
                // If the stack is empty after the above while loop, it means there is no bar with 
                // a smaller height than the current bar on its left side.
                leftBoundary[i] = 0;
            } else {
                // If the stack is not empty after the while loop, it means there is a bar with 
                // a smaller height than the current bar on its left side. In this case, we take 
                // the top element of the stack, which is the index of the bar with the smaller 
                // height, and add 1 to it to get the left boundary of the current bar.
                leftBoundary[i] = st.top() + 1;
            }

            // Finally, we push the current index (i) onto the stack to keep track of the bar's 
            // index for the next iterations.
            st.push(i);
        }

        // Clearing the stack to be re-used
        while(!st.empty()) {
            st.pop();
        }


        // Iterate through each bar's height in the 'heights' array.
        for (int i = n - 1; i >= 0; i--) {
            // While the stack is not empty and the height of the current bar (at index 'i')
            // is less than or equal to the height of the bar at the top of the stack,
            // keep popping elements from the stack.

            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // Now, the stack is either empty or contains the index of the bar with smaller height
            // than the current bar on its right side.

            // If the stack is empty, it means there is no bar with smaller height on the right side.
            // Therefore, the right boundary of the current bar (at index 'i') is considered to be the end of the histogram.
            if (st.empty()) {
                rightBoundary[i] = n - 1;
            } else {
                // If the stack is not empty, there is a bar with smaller height on the right side.
                // The right boundary of the current bar (at index 'i') is the index of that smaller height bar - 1.
                rightBoundary[i] = st.top() - 1;
            }

            // Push the current index ('i') onto the stack to keep track of the bar's index for the next iterations.
            st.push(i);
        }

        int maxArea = INT_MIN;

        for(int i = 0; i < heights.size(); i++) {
            maxArea = max(maxArea, (heights[i] * (rightBoundary[i] - leftBoundary[i] + 1)));
        }

        return maxArea;
    }
};

// ANALYSIS :
// Time Complexity  :- O(N^2)
// Space Complexity :- O(N)
