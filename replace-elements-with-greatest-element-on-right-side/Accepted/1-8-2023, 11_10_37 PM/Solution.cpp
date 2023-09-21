// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int val = -1;
        for (int i = arr.size() - 1; i >= 0; i--) {
            int curr = arr[i];
            arr[i] = val;
            val = max (val, curr);
        }
        return arr;
    }
};