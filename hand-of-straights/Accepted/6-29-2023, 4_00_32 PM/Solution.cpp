// https://leetcode.com/problems/hand-of-straights

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) {
            return false;
        }
        
        map<int, int> cardCounts;  // Map to store the count of each card
        
        // Count the occurrences of each card in the hand
        for (auto card : hand) {
            cardCounts[card]++;
        }

        sort(hand.begin(), hand.end());  // Sort the hand in ascending order

        for (int i = 0; i < hand.size(); i++) {
            if (cardCounts[hand[i]] == 0) {
                continue;  // Card already used or part of a group, skip it
            }

            // Check for consecutive cards required for the group
            for (int j = 0; j < groupSize; j++) {
                // Calculate the value of the current card in the iteration of the inner loop
                int currCard = hand[i] + j; 

                if (cardCounts[currCard] == 0) {
                    return false;  // Current card not available, can't form a group
                }

                cardCounts[currCard]--;  // Decrement the count of the current card
            }
        }

        return true;  // Able to form groups of size groupSize
    }
};
