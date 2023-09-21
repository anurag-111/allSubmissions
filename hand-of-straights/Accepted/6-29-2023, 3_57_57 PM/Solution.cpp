// https://leetcode.com/problems/hand-of-straights

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int , int> countHand;
        
        for(auto card : hand) {
            countHand[card]++;
        }

        sort(hand.begin(), hand.end());

        for(int i = 0; i < hand.size(); i++) {
            if(countHand[hand[i]] == 0) {
                continue;
            }

            for(int j = 0; j < groupSize; j++) {
                int currHand = hand[i] + j;

                if(countHand[currHand] == 0) {
                    return false;
                }

                countHand[currHand]--;
            }
        }

        return true;
    }
};