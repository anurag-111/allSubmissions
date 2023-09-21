// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Count the frequency of each number using an unordered map
        unordered_map<int, int> freq;
        for (auto num : nums) {
            freq[num]++;
        }
        
        // Create a min heap (priority queue) to store the top k frequent elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            pq.push({it->second, it->first});
            
            // If the size of the priority queue exceeds k, remove the smallest element
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        // Extract the top k frequent elements from the priority queue
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        // Return the top k frequent elements in reverse order
        reverse(result.begin(), result.end());
        return result;   
    }
};
