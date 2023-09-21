// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
      unordered_map<int, int> freq;
        
        for (int num : nums) {
            freq[num]++;
        }

        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
       
        for (auto it : freq) {
            int f = it.second;
            int num = it.first;
            buckets[f].push_back(num);
        }

        vector<int> result;
        
        for (int i = n; i >= 0; i--) {
            if ((buckets[i].size() > 0)) {
                for (int x : buckets[i]) {
                    if (k > 0) {
                        result.push_back(x);
                        k--;
                    }    
                }
            }
            
            if (k == 0) {
                break;
            }
            
        }
        
        return result;
        
    }
};