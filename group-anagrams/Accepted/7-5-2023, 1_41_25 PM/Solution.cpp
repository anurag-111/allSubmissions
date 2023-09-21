// https://leetcode.com/problems/group-anagrams

#include <vector>
#include <string>
#include <unordered_map>

class Solution {
private:
    // Helper function to generate an anagram key for a given string
    string generateAnagramKey(string& str) {
        int characterCounts[26] = {0};

        // Count the frequency of each character in the string
        for (char ch : str) {
            characterCounts[ch - 'a']++;
        }

        // Generate the anagram key based on the sorted counts
        string key = "";
        for (int i = 0; i < 26; i++) {
            if (characterCounts[i] > 0) {
                key += ('a' + i);
                key += to_string(characterCounts[i]);
            }
        }

        return key;
    }

public:
    // Function to group anagrams together
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagramGroups;
        unordered_map<string, vector<string>> anagramMap;

        // Group strings by their anagram keys
        for (string str : strs) {
            string currentString = str;
            string key = generateAnagramKey(currentString);
            anagramMap[key].push_back(currentString);
        }

        // Collect the groups of anagrams
        for (auto group : anagramMap) {
            anagramGroups.push_back(group.second);
        }

        return anagramGroups;
    }
};
