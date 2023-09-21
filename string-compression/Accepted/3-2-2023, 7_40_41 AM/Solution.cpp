// https://leetcode.com/problems/string-compression


class Solution {
public:
    int compress(vector<char>& chars) {
        
        int index = 0;
        int len = 0;
        int n = chars.size();
        
        while(index < n){
            
            char current = chars[index];
            int count = 0;
            while(index < n && chars[index] == current){
                index++;
                count++;
            }
            
            chars[len++] =  current;
            
            if(count > 1){
                string cnt = to_string(count);
                for(char ch : cnt){
                    chars[len++] = ch;
                }
            }
        }
        
        return len;
    }
};