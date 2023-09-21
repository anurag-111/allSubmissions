// https://leetcode.com/problems/smallest-number-in-infinite-set

class SmallestInfiniteSet {
public:
    set<int> st;
    int min;

    SmallestInfiniteSet() {
        min = 1;
    }
    
    int popSmallest() {
        if(!st.empty()) {
            int toRemove = *st.begin();
            st.erase(toRemove);
            return toRemove;
        } else {
            // Each time the set s is empty, min is incremented by 1, and the current value of min - 1 
            // is returned as the smallest element. This ensures that the function always returns the smallest 
            // possible integer that is not present in the set, maintaining the integrity of the 
            // "smallest infinite set" concept.
            min++;  
            return min - 1;
        }
    }
    
    void addBack(int num) {
        if(min > num) {
            st.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */