// https://leetcode.com/problems/find-the-town-judge

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> degree(n + 1, 0);

        // indegree - outdegree = n - 1 
        for(auto itr : trust) {
            degree[itr[0]]--; //out
            degree[itr[1]]++; //in
        }

        for(int i = 1; i <=n; i++) {
            if(degree[i] == n - 1) {
                return i;
            } 
        }
        return -1;

    }
};

/*
    Input: n = 4, trust = [[1,3], [1,4], [2,3], [2,4], [4,3]]

    degree : 0 -2 -2 +3 +1

    Output : 3
    As at index 3, we have value 3 which is equal to n - 1 --> 3.
*/
