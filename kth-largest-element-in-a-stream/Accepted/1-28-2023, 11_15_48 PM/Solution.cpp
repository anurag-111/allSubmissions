// https://leetcode.com/problems/kth-largest-element-in-a-stream

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k_value;

    //log(NlogN)
    KthLargest(int k, vector<int>& nums) {
        k_value = k;
        for (auto itr : nums) {
            pq.push(itr);
            if (pq.size() > k) {
            pq.pop();
        }
       
        }
    }
    
    //log(N)
    int add(int val) {
        pq.push(val);
        if (pq.size() > k_value) {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */