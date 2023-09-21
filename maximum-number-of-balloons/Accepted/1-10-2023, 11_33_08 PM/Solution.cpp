// https://leetcode.com/problems/maximum-number-of-balloons

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b=0, a=0, l=0, o=0, n=0;
            
        for (int i = 0; i < text.size(); i++){
            if (text[i] == 'b') {
                b++;    
            } 
            else if (text[i] == 'a') {
                a++;        
            } 
            else if (text[i] == 'l') {
                l++;
            } 
            else if (text[i] == 'o') {
                o++;
            }
            else if (text[i] == 'n') {
                n++;
            }
        }
        // l & o occours 2 times in the balloon
        int ans=min({b, a, l/2, o/2, n}); // min occourence of the char would be the solution
        return ans;
    }
};