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
        // Calculate the left boundary based on the given conditions
        int leftBoundary = max(value - targetIndex, 0);

        // Calculate the sum of the elements on the left side of the target index
        long sum = long(value + leftBoundary) * (value - leftBoundary + 1) / 2;

        // Calculate the right boundary based on the remaining elements on the right side of the target index
        int rightBoundary = max(value - ((length - 1) - targetIndex), 0);

        // Add the sum of the elements on the right side of the target index to the total sum
        sum += long(value + rightBoundary) * (value - rightBoundary + 1) / 2;

        // Subtract the value of 'value' itself, as it was included twice in the above calculations
        return sum - value;
    }
};
