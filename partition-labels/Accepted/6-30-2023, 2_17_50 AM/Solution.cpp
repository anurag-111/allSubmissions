// https://leetcode.com/problems/partition-labels

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mapChar;
        for(int i = 0; i < s.size(); i++) {
            mapChar[s[i]] = i;
        }

        int prev = -1;
        int maxCh = 0;
        vector<int> result;

        for(int i = 0; i < s.size(); i++) {
            maxCh = max(maxCh, mapChar[s[i]]);

            if(maxCh == i) {
                result.push_back(maxCh - prev);
                prev = maxCh;
            }
        }

        return result;
    }
};