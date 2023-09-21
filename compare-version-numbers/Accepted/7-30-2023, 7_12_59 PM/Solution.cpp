// https://leetcode.com/problems/compare-version-numbers

/* 

Objective
---------

The goal of the code is to compare two version strings version1 and version2, and return:
-1 if version1 is smaller than version2.
 1 if version1 is larger than version2.
 0 if they are equal.
 
Explanation
-----------
 
 Input: version1 = "1.2.3", version2 = "1.2.3.0"

    1. splitVersions("1.2.3")   -> Returns {1, 2, 3}
       splitVersions("1.2.3.0") -> Returns {1, 2, 3, 0}

    2. Compare {1, 2, 3} and {1, 2, 3, 0}:
       - num1 = 1, num2 = 1 -> Equal, continue to the next component
       - num1 = 2, num2 = 2 -> Equal, continue to the next component
       - num1 = 3, num2 = 3 -> Equal, continue to the next component
       - num1 = 0, num2 = 0 -> Both are 0, continue to the next component

    3. We have compared all components of both versions and found them equal.
       Return 0.

 Output: 0 (As both versions are equal)

*/


class Solution {
private:
    // Helper function to split version string and convert to integers
    vector<int> splitVersionString(string version) {
        vector<int> components;
        stringstream ss(version);
        string token;

        // Split the version string by '.'
        while (getline(ss, token, '.')) {
            components.push_back(stoi(token));
        }

        return components;
    }

public:
    int compareVersion(string version1, string version2) {
        // Split version strings into individual components
        vector<int> v1 = splitVersionString(version1);
        vector<int> v2 = splitVersionString(version2);

        // Find the maximum number of components in either version
        int maxLength = max(v1.size(), v2.size());

        // Compare the version components
        for (int i = 0; i < maxLength; i++) {
            int component1 = (i < v1.size()) ? v1[i] : 0; // Get current component of version1
            int component2 = (i < v2.size()) ? v2[i] : 0; // Get current component of version2

            if (component1 > component2) {
                return 1; // version1 is greater
            } else if (component1 < component2) {
                return -1; // version2 is greater
            }
            // If component1 and component2 are equal, move on to the next component
        }

        return 0; // Both versions are equal
    }
};


// Time Complexity: O(max(m, n)) + O(maxLength)
// Space Complexity: O(max(m, n))