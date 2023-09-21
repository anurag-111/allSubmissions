// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if (arr.size() <= 2) {
            return true;
        }

        int minimum = INT_MAX, maximum = INT_MIN;
        for (int num : arr) {
            minimum = min(minimum, num);
            maximum = max(maximum, num);
        }

        if ((maximum - minimum) % (arr.size() - 1) != 0) {
            return false;
        }

        int commonDifference = (maximum - minimum) / (arr.size() - 1);

        int i = 0;
        while (i < arr.size()) {
            if (arr[i] == minimum + i * commonDifference) {
                i++;
            } else if ((arr[i] - minimum) % commonDifference != 0) {
                return false;
            } else {
                int pos = (arr[i] - minimum) / commonDifference;
                if (pos < i || arr[pos] == arr[i]) {
                    return false;
                }
                swap(arr[i], arr[pos]);
            }
        }

        return true;
    }
};
