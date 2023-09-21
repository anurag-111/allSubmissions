// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
public:
    priority_queue<int> maxHeap; //MaxHeap to store a half of low numbers
    priority_queue<int, vector<int>, greater<int>> minHeap; //MinHeap to store a half of high numbers
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

// Time Complexity :
//  Constructor: O(1)
//  addNum: O(logN)
//  findMedian: O(1)
// Space: O(N)


//https://assets.leetcode.com/users/images/0eb8feba-cbfa-4f73-8d26-9aad226bdbc5_1626016093.9717174.png


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */