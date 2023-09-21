// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set <int> hashset;
        int longest_streak;
        
        for (auto num : nums) {
            hashset.insert(num);
        }
        
        for(auto num : nums) {
            if (!hashset.count(num-1)) {
                int current_num = num;
                int current_streak = 1;
            
                while (hashset.count(current_num+1)) {
                    current_num += 1;
                    current_streak += 1;
                }
                
                longest_streak = max (longest_streak, current_streak);
            }
        }
        
        return longest_streak;
        
        
    }
};