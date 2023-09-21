// https://leetcode.com/problems/arithmetic-subarrays

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        for (int i = 0, j = 0; i < l.size(); i++) {
           
            int x = l[i];
            int y = r[i];
            vector<int> vec;
            for(int i = x; i <= y; i++) {
                vec.push_back(nums[i]);
            }

            sort(vec.begin(), vec.end());

            for (j = 2; j < vec.size(); ++j) {
               if (vec[j] - vec[j - 1] != vec[1] - vec[0]) {
                     break;
                }
            }
                   
            if(j == vec.size()) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }
        return res;
    }
};

// Time Complexity : 
    // O(m * n * log n), where m is the number of queries

// Memory Complexity : 
    // O(n) to make a copy of an array.