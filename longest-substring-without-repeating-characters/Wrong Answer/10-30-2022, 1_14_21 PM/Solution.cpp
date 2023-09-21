// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char,int> umap;
        int start = 0;
        int max_len = 1;
        
        for(int end = 0; end < s.size(); end++) {
            char current = s[end]; 
            //check if current character already exists in map
            //update start as max(start, umap[current] + 1)
            if(umap.find(current) != umap.end()){
                start = max(start, umap[current] + 1); 
            }
            max_len = max(max_len, end-start+1);
            umap[current] = end;
        }
        return max_len;
    }
};