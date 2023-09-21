// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (!digits.size()) {
            return {};
        }
        unordered_map <char, string> umap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        string current = "";
        vector<string> result;

        dfs(digits, 0, umap, current, result);
        return result;
    }
private: 
    void dfs(string digits, int index, unordered_map <char, string>& umap, string& current, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        string str = umap[digits[index]];
        for(int i = 0; i < str.size(); i++) {
            current.push_back(str[i]);
            dfs(digits, index + 1, umap, current, result);
            current.pop_back();
        }
    }
};


/*
    Approach : 

    Hash map all digits to letters, add 1 letter at a time for each digit, 
    then backtrack to generate all possible combinations.

    Complexity : 
    
    Time: O(4^N * N), where N <= 4 is length of digits string. 
    Here, 4 is chosen assuming the worst case where each digit will be 7 or 9.
    
    Space (without counting output): O(N), it's the depth of stack memory.

*/
