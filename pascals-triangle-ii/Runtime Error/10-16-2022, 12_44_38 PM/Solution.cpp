// https://leetcode.com/problems/pascals-triangle-ii

//{n \ k} = {n-1 \ k-1} + {n-1 \ k}
//factor = (i-j)/(j+1)

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int val = 1;
        vector <int> result;
        
        for(int j = 0; j <= rowIndex; j++) {
            result.push_back(val);
            val = val * (rowIndex-j) / (j+1);
        }
        return result;
    }
};