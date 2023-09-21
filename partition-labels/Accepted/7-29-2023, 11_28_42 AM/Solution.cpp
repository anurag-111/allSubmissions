// https://leetcode.com/problems/partition-labels

class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Map to store the last occurrence index of each character in the string.
        unordered_map<char, int> lastOccurrence;

        // Populate the last occurrence index map.
        for (int i = 0; i < s.size(); i++) {
            lastOccurrence[s[i]] = i;
        }

        // Variables to keep track of the current partition's start and end.
        int partitionStart = 0;
        int partitionEnd = 0;

        vector<int> result;
        for (int i = 0; i < s.size(); i++) {
            // Update the partitionEnd with the maximum index encountered so far.
            partitionEnd = max(partitionEnd, lastOccurrence[s[i]]);

            // If the current index reaches the end of the current partition,
            // push the partition size into the result and update the partitionStart.
            if (i == partitionEnd) {
                result.push_back(partitionEnd - partitionStart + 1);
                partitionStart = partitionEnd + 1;
            }
        }
        return result;
    }
};
