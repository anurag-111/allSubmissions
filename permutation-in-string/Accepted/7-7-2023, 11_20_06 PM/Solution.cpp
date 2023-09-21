// https://leetcode.com/problems/permutation-in-string


class Solution {
public:
    bool checkInclusion(const string& s1, const string& s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> countFreq(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            countFreq[s1[i] - 'a']++;
            countFreq[s2[i] - 'a']--;
        }

        if (allZero(countFreq)) {
            return true;
        }

        for (int i = s1.size(); i < s2.size(); i++) {
            countFreq[s2[i] - 'a']--;
            countFreq[s2[i - s1.size()] - 'a']++;

            if (allZero(countFreq)) {
                return true;
            }
        }

        return false;
    }

private:
    bool allZero(const vector<int>& countFreq) {
        for (int count : countFreq) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }
};