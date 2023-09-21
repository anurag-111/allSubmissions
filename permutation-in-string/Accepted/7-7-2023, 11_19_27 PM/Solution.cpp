// https://leetcode.com/problems/permutation-in-string

class Solution {
private:
    bool allZero(vector<char> &count) {
        for(int i = 0; i < 26; i++) {
            if(count[i] != 0) {
                return false;
            }
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) {
            return false;
        }

        vector<char> countFreq(26, 0);

        for(int i = 0; i < s1.size(); i++){
            countFreq[s1[i] - 'a']++;
        }

        for(int i = 0; i < s2.size(); i++) {
            countFreq[s2[i] - 'a']--;

            if(i >= s1.size()) {
                countFreq[s2[i - s1.size()] - 'a']++;
            }

            if(allZero(countFreq)) {
                return true;
            }
        }
        return false;
    }
};
