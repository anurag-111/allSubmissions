// https://leetcode.com/problems/word-ladder

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> dict;
        for (string word: wordList) {
            dict.insert(word);
        }

        if(dict.find(endWord) == dict.end()) {
            return 0;
        }

        
        dict.erase(beginWord);

        // unordered_map<string, vector<string>> adj;
        // unordered_set<string> visited;
        // visited.insert(beginWord);
        // int len = 1;

        while (!q.empty()) {
            string word = q.front().first;
            int sequence = q.front().second;
            q.pop();

            if(word == endWord) {
                return sequence;
            }

            for (int i = 0; i < word.size(); i++) {
                char current = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch != current) {
                        word[i] = ch;
                        if (dict.find(word) != dict.end()) {
                            dict.erase(word);
                            q.push({word, sequence + 1});
                        }
                        //cout<<word<<endl;
                    }
                }
                word[i] = current;
            }   
        }         
        return 0;
    }
};