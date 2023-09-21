// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
      unordered_map<int, int> freq;
        
        for (int num : nums) {
            freq[num]++;
        }

        int n = nums.size();
        int counts[n + 1];
        
        for (int i = 0; i <= n; i++) {
            counts[i] = 0;
        }
       
        for (auto it : freq) {
            int f = it.second;
            int num = it.first;
            counts[f] = num;
        }

        vector<int> result;
        
        for (int i = n; i >= 0; i--) {
            
            if (counts[i] != 0 && (k > 0)) {
                result.push_back(counts[i]);
                k--;
            }
            
            if (k == 0) {
                break;
            }
            
        }
        
        return result;
        
    }
};