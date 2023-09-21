// https://leetcode.com/problems/boats-to-save-people

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int n = people.size();
        if(n == 0) {
            return 0;
        } 
        
        int boats = 0;
        sort(people.begin(), people.end());
        
        int i = 0, j = n - 1;

        while(i <= j){
            if(people[i] + people[j] <= limit){
                i++;
                j--;
            } else {
                j--;
            }
            boats++;
        }
        
        return boats;
    }
};