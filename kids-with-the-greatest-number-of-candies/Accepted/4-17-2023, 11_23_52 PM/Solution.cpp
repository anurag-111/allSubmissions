// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    
    vector<bool> out;

    // max_element() returns the iterator to the largest element in candies
    int max = *max_element(candies.begin(), candies.end());
    
    for(int i=0; i < candies.size(); i++) {
        if(candies[i]+extraCandies >= max) {
            out.push_back(true);
        } else {
            out.push_back(false);
        }
    }

    return out;
}
};
