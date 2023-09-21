// https://leetcode.com/problems/kth-largest-element-in-a-stream

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k_value;

    // Constructor to initialize the KthLargest object
    KthLargest(int k, vector<int>& nums) {
        k_value = k;
        
        // Inserting elements from nums into the priority queue
        for (auto itr : nums) {
            pq.push(itr);
            
            // If the size of priority queue exceeds k, remove the smallest element
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }
    
    // Function to add a new element and return the kth largest element
    int add(int val) {
        pq.push(val);
        
        // If the size of priority queue exceeds k, remove the smallest element
        if (pq.size() > k_value) {
            pq.pop();
        }
        
        return pq.top(); // Return the current kth largest element
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
