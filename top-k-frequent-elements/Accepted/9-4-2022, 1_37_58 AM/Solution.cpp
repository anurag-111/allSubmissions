// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        typedef pair<int, int> pr;
        for(auto num : nums){
            freq[num]++;
        }
        priority_queue<pr, vector<pr>,greater<pr>> p;
        for(auto i =  freq.begin(); i != freq.end(); i++){
            p.push({i->second,i->first});
            if(p.size() > k)
                p.pop();
        }
        vector<int> v;
        while(!p.empty()){
            v.push_back(p.top().second);
            p.pop();
        }
        return v;   
    }
};