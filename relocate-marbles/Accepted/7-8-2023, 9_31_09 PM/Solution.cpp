// https://leetcode.com/problems/relocate-marbles

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        // Sort the nums vector and remove duplicates
        sort(nums.begin(), nums.end());

        unordered_map<int, int> marbleMap;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            marbleMap[nums[i]] = 1;
        }

        int m = moveFrom.size();
        for (int i = 0; i < m; i++) {
            if (marbleMap.find(moveFrom[i]) != marbleMap.end()) {
                // Marble found in the map
                marbleMap.erase(moveFrom[i]);
                marbleMap[moveTo[i]] = 1;
            }
        }

        vector<int> relocatedMarbles;
        for (auto it : marbleMap) {
            relocatedMarbles.push_back(it.first);
        }

        sort(relocatedMarbles.begin(), relocatedMarbles.end());
        return relocatedMarbles;
    }
};
