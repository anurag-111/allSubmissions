// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        //s = anagram
        // a -> 2
        // n -> 1
        // g -> 1
        // r -> 1
        // m -> 1
        unordered_map<char, int> sFrequency;
        unordered_map<char, int> tFrequency;
        
        for (char ch : s) {
            sFrequency[ch]++;
        }
        
        for (char ch : t) {
            tFrequency[ch]++;
        }
        
        for (auto itr : sFrequency) {
            char key = itr.first;
            int value = itr.second;
            
            if (tFrequency[key] != value) {
                return false;
            }
        }
        
        return true;
    }
};