// https://leetcode.com/problems/partition-labels

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> charMap;

        // Create a map to store the last occurrence of each character
        for (int i = 0; i < s.size(); i++) {
            charMap[s[i]] = i;
        }

        int prev = -1;
        int maxCharIndex = 0;
        vector<int> result;

        // Iterate through the string
        for (int i = 0; i < s.size(); i++) {
            maxCharIndex = max(maxCharIndex, charMap[s[i]]);

            // If the current index is equal to the maximum character index encountered so far,
            // it means we have found a partition
            if (maxCharIndex == i) {
                result.push_back(maxCharIndex - prev);
                prev = maxCharIndex;
            }
        }

        return result;
    }
};
