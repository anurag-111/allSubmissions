// https://leetcode.com/problems/simplify-path

class Solution {
public:
    string simplifyPath(string path) {
        string res, token;
        vector<string> stk;
        stringstream ss(path);

        while(getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            }
            if (token == ".." && !stk.empty()) {
                stk.pop_back();
            } else if (token != "..") {
                stk.push_back(token);
            }
        }
        
        for(auto str : stk) {
            res = res + "/" + str;
        }
        
        return res.empty() ? "/" : res;
    }
};