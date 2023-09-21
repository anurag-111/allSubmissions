// https://leetcode.com/problems/time-needed-to-inform-all-employees

#include <unordered_map>
#include <vector>

class Solution {
public:
    std::unordered_map<int, std::vector<int>> subordinates;
    int totalMinutes = 0;
    int maxMinutes = 0;
    
    void dfs(int manager, std::vector<int>& informTime) {
        maxMinutes = std::max(maxMinutes, totalMinutes);
        
        for (auto subordinate : subordinates[manager]) {
            totalMinutes += informTime[manager];
            dfs(subordinate, informTime);
            totalMinutes -= informTime[manager];  // backtrack
        }
    }
    
    int numOfMinutes(int n, int headID, std::vector<int>& manager, std::vector<int>& informTime) {
        for (int i = 0; i < n; i++) {
            int directManager = manager[i];
            if (directManager != -1) {
                subordinates[directManager].push_back(i);
            }
        }
        
        dfs(headID, informTime);
        return maxMinutes;
    }
};
