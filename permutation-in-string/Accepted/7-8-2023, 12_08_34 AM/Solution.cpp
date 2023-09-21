// https://leetcode.com/problems/permutation-in-string

class Solution
{
    public:
        bool checkInclusion(const string &s1, const string &s2) {
            if (s1.size() > s2.size()) {
                return false;
            }

           	// Create a vector to store the frequency count of each character
            vector<int> countFreq(26, 0);

           	// Update the countFreq vector by subtracting the counts of characters in s2 from s1
           	// The countFreq vector will represent the difference in frequency counts between s1 and the sliding window in s2
            for (int i = 0; i < s1.size(); i++) {
                countFreq[s1[i] - 'a']++;	// Increment count for character in s1
                countFreq[s2[i] - 'a']--;	// Decrement count for character in s2
            }

           	// Check if the countFreq vector is already all zeros, indicating s1 is a permutation of the initial window in s2
            if (allZero(countFreq)) {
                return true;
            }

           	// Slide the window over s2 and update the countFreq vector accordingly
            for (int i = s1.size(); i < s2.size(); i++) {
                countFreq[s2[i] - 'a']--;	// Decrement count for new character in the window
                countFreq[s2[i - s1.size()] - 'a']++;	// Increment count for character going out of the window

               	// Check if the countFreq vector is all zeros after each window slide
                if (allZero(countFreq)){
                    return true;
                }
            }

           	// No permutation of s1 found in s2
            return false;
        }

    private:
       	// Helper function to check if all counts in the countFreq vector are zero
        bool allZero(const vector<int> &countFreq) {
            for (int count: countFreq) {
                if (count != 0) {
                    return false;
                }
            }
            return true;
        }
};