// https://leetcode.com/problems/add-to-array-form-of-integer

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> result;
        int len = num.size() - 1;

        while (len >= 0 || k != 0) {
            if(len >= 0) {
                k += num[len];
                len--;
            }

            result.push_back(k % 10);
            k = k / 10;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

/*
    Time Complexity : O(max(n, log10(k))), where n is the length of the array and log10(k) is the number of digits present in variable k.

    Space Complexity : O(max(n, log10(k))), not an in-place as we need space equal to the given k or length of array, 
    whichever is maximum between the two, to store the elements.
*/