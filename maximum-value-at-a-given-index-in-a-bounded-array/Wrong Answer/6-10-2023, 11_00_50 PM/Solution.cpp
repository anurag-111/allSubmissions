// https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array

class Solution {
public:
    int maxValue(int length, int targetIndex, int maxSum) {
        maxSum -= length;

        int left = 0, right = maxSum, mid;

        while (left < right) {
            mid = (left + right + 1) / 2;

            if (calculateSum(length, targetIndex, mid) <= maxSum)
                left = mid;
            else
                right = mid - 1;
        }

        return left + 1;
    }

    long calculateSum(int length, int targetIndex, int value) {
        int leftBoundary = max(value - targetIndex, 0);
        int rightBoundary = max(value - (length - 1 - targetIndex), 0);
        int totalElements = length - 1;

        long sum = (long)value * (value + 1) / 2; // Sum of elements up to 'value'
        sum -= (long)leftBoundary * (leftBoundary + 1) / 2; // Subtract the elements on the left side of targetIndex
        sum -= (long)rightBoundary * (rightBoundary + 1) / 2; // Subtract the elements on the right side of targetIndex
        sum += leftBoundary + rightBoundary; // Add back the value of the boundaries

        return sum;
    }
};
