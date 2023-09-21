// https://leetcode.com/problems/can-place-flowers

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count  = 0;
        int prev, next;

        for(int i = 0; i < flowerbed.size(); i++) {
            if(flowerbed[i] == 0) {
                if(i == 0 || flowerbed[i - 1] == 0) {
                    prev = 0; // empty
                } else {
                    prev = 1; // occupied 
                }

                if(i == flowerbed.size() - 1 || flowerbed[i + 1] == 0) {
                    next = 0; // empty
                } else {
                    next = 1; // occupied 
                }

                if(prev == 0 && next == 0) {
                    flowerbed[i] = 1;
                    count++;
                }
            }
        }     
        return count >= n; //return if n new flowers can be planted in the flowerbed 
                           //without violating the no-adjacent-flowers rule.
    }
};