// https://leetcode.com/problems/naming-a-company

class Solution {
public:
    long distinctNames(vector<string> ideas) {
        
        // Each unordered_set will store strings starting with the same character.
        unordered_set<string> groups[26];       
        
        // Insert each string into the unordered_set corresponding to its first character.
        for (auto idea : ideas) {
            groups[idea[0] - 'a'].insert(idea.substr(1));
        }

        long answer = 0; 
        // Group the words and put the suffix into their respective hashsets.
        for (int i = 0; i < 25; ++i) {
            // Initialise i = 0 and j =i at every step(to form pairs).
            for (int j = i + 1; j < 26; ++j) {   
                long mutuals = 0;                              
                for (auto ideaA : groups[i]) {
                    if (groups[j].count(ideaA)) {
                        // Count mutual suffix or words b/w the 2 hashsets.
                        mutuals++;
                    }
                }
                answer += 2 * (groups[i].size() - mutuals) * (groups[j].size() - mutuals);
            }
        }
        
        return answer;
    }
};