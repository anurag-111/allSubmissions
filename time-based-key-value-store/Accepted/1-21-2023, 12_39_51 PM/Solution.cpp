// https://leetcode.com/problems/time-based-key-value-store

class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> umap;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        umap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        
        if(umap.find(key) == umap.end()) {
          return "";
        }

        int low = 0;
        int high = umap[key].size()-1;

        if(umap[key][0].first > timestamp) {
            return "";
        }

        string ans;

        while(low <= high) {
        int mid = low + (high - low) / 2;

        if (umap[key][mid].first == timestamp) {
            return umap[key][mid].second;
        } else if (umap[key][mid].first < timestamp) {
            ans = umap[key][mid].second;
            low = mid+1;
        } else {
            high = mid-1;
          }

    }

    return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */