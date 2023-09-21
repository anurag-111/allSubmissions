// https://leetcode.com/problems/scramble-string

class Solution {
  unordered_map<string, bool> dp;
  bool scrambleAndMatch(string s1, string s2) {
    int n = s1.length();

    if (n == 1) {
        return (s1 == s2);
    }
    if (s1 == s2) {
        return true;
    }

    string key = s1 + "." + s2;

    if (dp.find(key) != dp.end()) {
        return dp[key];
    }

    for (int i = 1; i < n; i++) {
        if (scrambleAndMatch(s1.substr(0, i), s2.substr(0, i)) && scrambleAndMatch(s1.substr(i), s2.substr(i))) {
            return dp[key] = true;
        }

        if (scrambleAndMatch(s1.substr(0, i), s2.substr(n-i)) && scrambleAndMatch(s1.substr(i), s2.substr(0, n-i))) {
            return dp[key] = true;
        }
    }

    return dp[key] = false;
  }

  bool scrambleAndMatch(int start, int end, int matchStart, int matchEnd, string& s1, string& s2) {
    // cout << start << "\t" << end << "\t" << matchStart << "\t" << matchEnd << endl;
    // cout << s1.substr(start, end-start+1) << "\t" <<  s2.substr(matchStart, matchEnd-matchStart+1) << endl;
    
    if (start == end) {
        return s1[start] == s2[matchStart];
    }


    for (int i = 1; start + i < end; i++) {
      if (scrambleAndMatch(start, start + i - 1, matchStart, matchStart + i - 1, s1, s2) &&
          scrambleAndMatch(start + i, end, matchStart + i, matchEnd, s1, s2)) {
              return true;
          }
      
      if (scrambleAndMatch(start, start+i-1, matchEnd-i+1, matchEnd, s1, s2) &&
          scrambleAndMatch(start+i, end, matchStart, matchEnd-i, s1, s2)) {
              return true;
          }
    }

    return false;
  }

public:
  bool isScramble(string s1, string s2) {
    if (s1.length() == 1) {
        return s1 == s2;
    }

    // return scrambleAndMatch(0, s1.length()-1, 0, s2.length()-1, s1, s2);
    //dp.clear();
    
    return scrambleAndMatch(s1, s2);
  }
};